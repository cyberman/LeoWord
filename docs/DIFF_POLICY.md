# LeoWord Diff Policy

Later AbiWord changes may be imported only if they are useful for the Leopard/PPC target.

Diff classes:

- SAFE: isolated bugfix, no new dependency
- CANDIDATE: useful feature or file format improvement
- SUSPICIOUS: architectural change requiring review
- REJECT: GTK3, GNOME integration, modern C++ assumptions, dependency expansion

AbiWord 2.4.5 is the source of truth.
