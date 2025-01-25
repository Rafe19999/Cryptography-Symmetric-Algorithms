#include <iostream>
#include <bitset>
using namespace std;

// Simple XOR-based round function
bitset<4> roundFunction(bitset<4> half, bitset<4> key) {
    return half ^ key;
}

// Feistel Cipher Encryption
pair<bitset<4>, bitset<4>> encrypt(bitset<4> L0, bitset<4> R0, bitset<4> K1, bitset<4> K2) {
    // Round 1
    bitset<4> L1 = R0;
    bitset<4> R1 = L0 ^ roundFunction(R0, K1);

    // Round 2
    bitset<4> L2 = R1;
    bitset<4> R2 = L1 ^ roundFunction(R1, K2);

    // Swap L2 and R2 for final output
    return {R2, L2};
}

// Feistel Cipher Decryption
pair<bitset<4>, bitset<4>> decrypt(bitset<4> L2, bitset<4> R2, bitset<4> K1, bitset<4> K2) {
    // Undo the swap
    bitset<4> R1 = L2;
    bitset<4> L1 = R2;

    // Reverse Round 2
    bitset<4> R0 = L1;
    bitset<4> L0 = R1 ^ roundFunction(R0, K2);

    // Reverse Round 1
    return {L0, R0};
}

int main() {
    // Input 8-bit plaintext (split into 4-bit halves)
    bitset<4> L0("1101"); // Left half of the plaintext
    bitset<4> R0("1010"); // Right half of the plaintext

    // Keys for the two rounds (4-bit each)
    bitset<4> K1("0110");
    bitset<4> K2("1001");

    cout << "Plaintext L0: " << L0 << ", R0: " << R0 << endl;

    // Encryption
    auto [L2, R2] = encrypt(L0, R0, K1, K2);
    cout << "Encrypted L2: " << L2 << ", R2: " << R2 << endl;

    // Decryption
    auto [L0_dec, R0_dec] = decrypt(L2, R2, K1, K2);
    cout << "Decrypted L0: " << L0_dec << ", R0: " << R0_dec << endl;

    return 0;
}
