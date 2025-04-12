# Cyclic-Redundancy-Check

# Description

This project implements a method for error detection and correction:

Cyclic Redundancy Check (CRC) – a generator polynomial is applied to the binary message to compute the remainder of the polynomial division using successive XOR operations.

# Features

✔️ Validates that input messages are binary.

✔️ Ensures that the message length is greater than the number of generator polynomial coefficients.

✔️ Extends the message by appending zeros equal to the polynomial’s degree.

✔️ Performs successive XOR operations to compute the CRC remainder.

✔️ Displays intermediate XOR results.

✔️ Applies XOR between the extended message and the final remainder to generate the final encoded message.


# Example Run

![image](https://github.com/user-attachments/assets/b24aab30-c6e6-4755-984c-b41fbc72ffe1)


![image](https://github.com/user-attachments/assets/42f9a531-568c-4a3e-8ab8-3ac67df3bffb)


![image](https://github.com/user-attachments/assets/379e3265-7a12-4b27-9a1d-6be7c32bd803)
