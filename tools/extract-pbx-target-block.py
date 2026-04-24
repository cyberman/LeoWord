#!/usr/bin/env python3
import sys

if len(sys.argv) != 3:
    print("Usage: extract-pbx-target-block.py <project.pbxproj> <target-name>")
    sys.exit(1)

path = sys.argv[1]
target_name = sys.argv[2]

with open(path, "r", encoding="utf-8", errors="replace") as f:
    text = f.read()

objects_pos = text.find("\tobjects = {")
if objects_pos < 0:
    print("Could not find objects section", file=sys.stderr)
    sys.exit(1)

i = objects_pos
matches = []

while True:
    start = text.find("\n\t\t", i)
    if start < 0:
        break

    eq = text.find(" = {", start)
    if eq < 0:
        break

    obj_id = text[start:eq].strip()
    block_start = text.find("{", eq)
    depth = 0
    j = block_start

    while j < len(text):
        if text[j] == "{":
            depth += 1
        elif text[j] == "}":
            depth -= 1
            if depth == 0:
                block_end = j + 1
                break
        j += 1
    else:
        break

    block = text[start:block_end + 2]

    if "isa = PBXNativeTarget;" in block and f"name = {target_name};" in block:
        matches.append(block)

    i = block_end

if not matches:
    print(f"Target not found: {target_name}", file=sys.stderr)
    sys.exit(2)

for block in matches:
    print(block)
