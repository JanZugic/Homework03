#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

const int MAX_ROWS = 20;
const int MAX_COLS = 40;

void drawGrid(int startRow, int startCol, int endRow, int endCol) {
    system("cls");  // Clear the console

    for (int row = 1; row <= MAX_ROWS; ++row) {
        for (int col = 1; col <= MAX_COLS; ++col) {
            if (row == startRow && col == startCol) {
                cout << "A ";
            }
            else if (row == endRow && col == endCol) {
                cout << "B ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }

    this_thread::sleep_for(chrono::milliseconds(100));
}

int getUserInput(const string& prompt, int maxLimit) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        if (input >= 1 && input <= maxLimit) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a number between 1 and " << maxLimit << "." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return input;
}

int main() {
    int startRow = getUserInput("Enter the row of the starting point A: ", MAX_ROWS);
    int startCol = getUserInput("Enter the column of the starting point A: ", MAX_COLS);

    int endRow = getUserInput("Enter the row of the endpoint B: ", MAX_ROWS);
    int endCol = getUserInput("Enter the column of the endpoint B: ", MAX_COLS);

    drawGrid(startRow, startCol, endRow, endCol);

    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;

    int rowStep = (rowDiff > 0) ? 1 : -1;
    int colStep = (colDiff > 0) ? 1 : -1;

    while (startRow != endRow || startCol != endCol) {
        if (startRow != endRow) {
            startRow += rowStep;
        }
        if (startCol != endCol) {
            startCol += colStep;
        }

        drawGrid(startRow, startCol, endRow, endCol);
    }

    return 0;
}
