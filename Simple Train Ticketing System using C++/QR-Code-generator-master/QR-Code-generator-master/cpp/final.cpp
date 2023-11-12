#include <cstdlib>
#include <iostream>
#include <string>
#include "qrcodegen.hpp"

using qrcodegen::QrCode;

// Function prototypes
void doVarietyDemo();
void printQr(const QrCode &qr);

// The main application program.
int main() {
    doVarietyDemo();
    return EXIT_SUCCESS;
}

/*---- Demo suite ----*/

// Creates a variety of QR Codes that exercise different features of the library, and prints each one to the console.
void doVarietyDemo() {
    // Numeric mode encoding (3.33 bits per digit)
    const QrCode qr0 = QrCode::encodeText("314159265358979323846264338327950288419716939937510", QrCode::Ecc::MEDIUM);
    printQr(qr0);
}

/*---- Utilities ----*/

// Prints the given QrCode object to the console.
void printQr(const QrCode &qr) {
    int border = 4;
    for (int y = -border; y < qr.getSize() + border; y++) {
        for (int x = -border; x < qr.getSize() + border; x++) {
            std::cout << (qr.getModule(x, y) ? "##" : "  ");
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
