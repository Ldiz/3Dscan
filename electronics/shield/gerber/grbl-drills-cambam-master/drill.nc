( pcb2gcode 1.1.4 )

( This file uses 2 drill bit sizes. )

G94     ( Inches per minute feed rate. )
G20     ( Units == INCHES.             )
G90     ( Absolute coordinates.        )
S100  ( RPM spindle speed.           )

G00 Z0.98425 ( Retract )
T1
M5      ( Spindle stop.                )
M6      ( Tool change.                 )
(MSG, CHANGE TOOL BIT: to drill size 0.03200 inch)
M0      ( Temporary machine stop.      )
M3      ( Spindle on clockwise.        )

G81 R0.07874 Z0.05906 F3.93701 X-6.84000 Y-5.45000
X-6.94000 Y-5.45000
X-7.04000 Y-5.45000
X-7.14000 Y-5.45000
X-7.20000 Y-7.35000
X-7.24000 Y-5.45000
X-7.30000 Y-7.35000
X-7.34000 Y-5.45000
X-7.40000 Y-7.35000
X-7.44000 Y-5.45000
X-7.50000 Y-7.35000
X-7.54000 Y-5.45000
X-7.60000 Y-7.35000
X-7.70000 Y-5.45000
X-7.70000 Y-7.35000
X-7.80000 Y-5.45000
X-7.90000 Y-5.45000
X-7.90000 Y-7.35000
X-8.00000 Y-5.45000
X-8.00000 Y-7.35000
X-8.10000 Y-5.45000
X-8.10000 Y-7.35000
X-8.20000 Y-5.45000
X-8.20000 Y-7.35000
X-8.30000 Y-5.45000
X-8.30000 Y-7.35000
X-8.40000 Y-5.45000
X-8.40000 Y-7.35000


G00 Z0.98425 ( Retract )
T2
M5      ( Spindle stop.                )
M6      ( Tool change.                 )
(MSG, CHANGE TOOL BIT: to drill size 0.12500 inch)
M0      ( Temporary machine stop.      )
M3      ( Spindle on clockwise.        )

G81 R0.07874 Z0.05906 F3.93701 X-6.45000 Y-7.35000
X-6.50000 Y-5.45000
X-8.50000 Y-6.05000
X-8.50000 Y-7.15000


G00 Z0.98425 ( All done -- retract )

M9 ( Coolant off. )
M2 ( Program end. )

