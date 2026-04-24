#!/usr/bin/env python3
import re
import sys

if len(sys.argv) < 3:
    print("Usage: resolve-pbx-build-phase-files.py <project.pbxproj> <phase-id> [phase-id...]")
    sys.exit(1)

path = sys.argv[1]
phase_ids = sys.argv[2:]

with open(path, "r", encoding="utf-8", errors="replace") as f:
    text = f.read()

def extract_object(obj_id):
    marker = "\n\t\t" + obj_id + " = {"
    start = text.find(marker)
    if start < 0:
        return None

    brace = text.find("{", start)
    depth = 0

    for i in range(brace, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                return text[start:i + 2]

    return None

def get_scalar(block, key):
    if not block:
        return ""
    m = re.search(r'\b' + re.escape(key) + r' = ([^;]+);', block)
    if not m:
        return ""
    return m.group(1).strip().strip('"')

def get_files(block):
    m = re.search(r'files = \((.*?)\);', block, re.S)
    if not m:
        return []
    raw = m.group(1)
    ids = []
    for line in raw.splitlines():
        line = line.strip().rstrip(",")
        if re.fullmatch(r'[A-F0-9]{24}', line):
            ids.append(line)
    return ids

def object_label(obj_id):
    block = extract_object(obj_id)
    if not block:
        return f"{obj_id} <missing>"

    isa = get_scalar(block, "isa")

    # PBXBuildFile usually points to a PBXFileReference via fileRef.
    file_ref = get_scalar(block, "fileRef")
    if file_ref:
        ref_block = extract_object(file_ref)
        ref_isa = get_scalar(ref_block, "isa")
        path_value = get_scalar(ref_block, "path")
        name_value = get_scalar(ref_block, "name")
        source_tree = get_scalar(ref_block, "sourceTree")
        last_known = get_scalar(ref_block, "lastKnownFileType")
        explicit = get_scalar(ref_block, "explicitFileType")

        display = path_value or name_value or file_ref
        meta = []
        if ref_isa:
            meta.append(ref_isa)
        if last_known:
            meta.append(last_known)
        if explicit:
            meta.append(explicit)
        if source_tree:
            meta.append(f"sourceTree={source_tree}")

        if meta:
            return f"{display}  [{', '.join(meta)}]"
        return display

    path_value = get_scalar(block, "path")
    name_value = get_scalar(block, "name")
    return path_value or name_value or f"{obj_id} [{isa}]"

for phase_id in phase_ids:
    phase = extract_object(phase_id)
    if not phase:
        print(f"## {phase_id}: <missing>")
        print()
        continue

    phase_isa = get_scalar(phase, "isa")
    dst_path = get_scalar(phase, "dstPath")
    dst_subfolder = get_scalar(phase, "dstSubfolderSpec")
    shell_script = get_scalar(phase, "shellScript")

    print(f"## {phase_id}")
    print()
    print(f"- isa: {phase_isa}")

    if dst_path:
        print(f"- dstPath: {dst_path}")
    if dst_subfolder:
        print(f"- dstSubfolderSpec: {dst_subfolder}")
    if shell_script:
        print(f"- shellScript: {shell_script}")

    files = get_files(phase)
    print(f"- file count: {len(files)}")
    print()

    for build_file_id in files:
        print(f"- {object_label(build_file_id)}")

    print()
