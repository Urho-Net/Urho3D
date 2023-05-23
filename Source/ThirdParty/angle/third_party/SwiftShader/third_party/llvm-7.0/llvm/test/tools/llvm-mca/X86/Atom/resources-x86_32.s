# NOTE: Assertions have been autogenerated by utils/update_mca_test_checks.py
# RUN: llvm-mca -mtriple=i686-unknown-unknown -mcpu=atom -instruction-tables < %s | FileCheck %s

aaa

aad
aad $7

aam
aam $7

aas

bound %bx, (%eax)
bound %ebx, (%eax)

daa

das

into

leave

salc

# CHECK:      Instruction Info:
# CHECK-NEXT: [1]: #uOps
# CHECK-NEXT: [2]: Latency
# CHECK-NEXT: [3]: RThroughput
# CHECK-NEXT: [4]: MayLoad
# CHECK-NEXT: [5]: MayStore
# CHECK-NEXT: [6]: HasSideEffects (U)

# CHECK:      [1]    [2]    [3]    [4]    [5]    [6]    Instructions:
# CHECK-NEXT:  1      13    6.50                        aaa
# CHECK-NEXT:  1      7     3.50                        aad
# CHECK-NEXT:  1      7     3.50                        aad	$7
# CHECK-NEXT:  1      21    10.50                       aam
# CHECK-NEXT:  1      21    10.50                       aam	$7
# CHECK-NEXT:  1      13    6.50                        aas
# CHECK-NEXT:  1      11    5.50                  U     bound	%bx, (%eax)
# CHECK-NEXT:  1      11    5.50                  U     bound	%ebx, (%eax)
# CHECK-NEXT:  1      18    9.00                        daa
# CHECK-NEXT:  1      20    10.00                       das
# CHECK-NEXT:  1      6     3.00                  U     into
# CHECK-NEXT:  1      2     1.00    *                   leave
# CHECK-NEXT:  1      1     0.50                  U     salc

# CHECK:      Resources:
# CHECK-NEXT: [0]   - AtomPort0
# CHECK-NEXT: [1]   - AtomPort1

# CHECK:      Resource pressure per iteration:
# CHECK-NEXT: [0]    [1]
# CHECK-NEXT: 75.50  75.50

# CHECK:      Resource pressure by instruction:
# CHECK-NEXT: [0]    [1]    Instructions:
# CHECK-NEXT: 6.50   6.50   aaa
# CHECK-NEXT: 3.50   3.50   aad
# CHECK-NEXT: 3.50   3.50   aad	$7
# CHECK-NEXT: 10.50  10.50  aam
# CHECK-NEXT: 10.50  10.50  aam	$7
# CHECK-NEXT: 6.50   6.50   aas
# CHECK-NEXT: 5.50   5.50   bound	%bx, (%eax)
# CHECK-NEXT: 5.50   5.50   bound	%ebx, (%eax)
# CHECK-NEXT: 9.00   9.00   daa
# CHECK-NEXT: 10.00  10.00  das
# CHECK-NEXT: 3.00   3.00   into
# CHECK-NEXT: 1.00   1.00   leave
# CHECK-NEXT: 0.50   0.50   salc
