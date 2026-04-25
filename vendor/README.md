# LeoWord vendor policy

LeoWord currently keeps AbiWord 2.4.5 as the primary restoration source.

Other AbiWord snapshots are not kept in the active working tree to keep Git and SMB-based workflows manageable.

Primary vendor source:

- `vendor/abiword-2.4.5`

Removed/deferred references:

- AbiWord 2.8.6
- current AbiWord/GNOME tree

Diff-based backports from later AbiWord versions should be documented before importing code.
