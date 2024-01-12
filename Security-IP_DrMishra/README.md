# SecurityIP

Each directory contains modules for the named IP (for example, AES/GCM will be IP for AES GCM mode).

NOTE: ECIES and ECDSA are both ECC-based IP. The ECCShared modules will be used inside them.

AES GCM and XTS modes use the Galois multiplication module.

The AES modules will use code from https://opencores.org/projects/tiny_aes and https://github.com/secworks/aes

VulnerabilityAnalysisReport.txt gives an analysis of vulnerability and mitigation for all IPs.