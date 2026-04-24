#!/usr/bin/env python3
import re
import sys

if len(sys.argv) != 2:
    print("Usage: extract-pbx-target-summary.py <project.pbxproj>")
    sys.exit(1)

path = sys.argv[1]

with open(path, "r", encoding="utf-8", errors="replace") as f:
    text = f.read()

blocks = re.findall(r'([A-F0-9]{24}) = \{(.*?)\n\t\t\};', text, re.S)

targets = []

for obj_id, block in blocks:
    if "isa = PBXNativeTarget;" not in block:
        continue

    def get_value(key):
        match = re.search(r'\b' + re.escape(key) + r' = ([^;]+);', block)
        if match:
            return match.group(1).strip().strip('"')
        return ""

    name = get_value("name")
    product_name = get_value("productName")
    product_type = get_value("productType")

    # Pull selected build settings from the target-local buildSettings block.
    settings = {}
    settings_match = re.search(r'buildSettings = \{(.*?)\n\t\t\t\t\};', block, re.S)
    if settings_match:
        settings_block = settings_match.group(1)
        for key in [
            "PRODUCT_NAME",
            "MACOSX_DEPLOYMENT_TARGET",
            "EXECUTABLE_EXTENSION",
            "INSTALL_PATH",
            "LIBRARY_STYLE",
            "HEADER_SEARCH_PATHS",
            "FRAMEWORK_SEARCH_PATHS",
            "OTHER_LDFLAGS",
            "GCC_PREPROCESSOR_DEFINITIONS",
        ]:
            m = re.search(r'\b' + re.escape(key) + r' = (.*?);', settings_block, re.S)
            if m:
                value = " ".join(m.group(1).strip().split())
                settings[key] = value

    targets.append((name, product_name, product_type, settings))

print("# AbiWord 2.4.5 PBX Target Summary")
print()
print("Target count:", len(targets))
print()

for index, (name, product_name, product_type, settings) in enumerate(targets, 1):
    print(f"## {index}. {name}")
    print()
    print(f"- productName: {product_name}")
    print(f"- productType: {product_type}")
    for key, value in settings.items():
        print(f"- {key}: {value}")
    print()
