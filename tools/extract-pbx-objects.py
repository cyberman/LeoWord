#!/usr/bin/env python3
import sys

if len(sys.argv) < 3:
    print("Usage: extract-pbx-objects.py <project.pbxproj> <object-id> [object-id...]")
    sys.exit(1)

path = sys.argv[1]
wanted = set(sys.argv[2:])

with open(path, "r", encoding="utf-8", errors="replace") as f:
    text = f.read()

for obj_id in wanted:
    marker = "\n\t\t" + obj_id + " = {"
    start = text.find(marker)
    if start < 0:
        print(f"// Object not found: {obj_id}")
        continue

    brace = text.find("{", start)
    depth = 0
    end = None

    for i in range(brace, len(text)):
        if text[i] == "{":
            depth += 1
        elif text[i] == "}":
            depth -= 1
            if depth == 0:
                end = i + 2
                break

    if end is None:
        print(f"// Unterminated object: {obj_id}")
        continue

    print(text[start:end])
    print()
