
import string
from math import gcd

# Cipher text
ciphertext = "IHHWVC SWFRCP"

alphabet = string.ascii_uppercase

# Try all possible keys
for a in range(1, 26):
    if gcd(a, 26) == 1:

        # Find modular inverse
        a_inv = pow(a, -1, 26)

        for b in range(26):
            plaintext = ""

            for ch in ciphertext:
                if ch in alphabet:
                    y = alphabet.index(ch)
                    x = (a_inv * (y - b)) % 26
                    plaintext += alphabet[x]
                else:
                    plaintext += ch

            print("Key:", a, b,
                  "Plaintext:", plaintext)

