# LeoWord Diff Policy

Later AbiWord changes may be imported only if they are useful for the Leopard/PPC target.

## Diff Classes

### SAFE

Isolated bugfix, no new dependency.

### CANDIDATE

Useful feature or file format improvement.

### SUSPICIOUS

Architectural change requiring review.

### REJECT

GTK3, GNOME integration, modern C++ assumptions, dependency expansion.

## Baseline Rule

AbiWord 2.4.5 is the source of truth.
