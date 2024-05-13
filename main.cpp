#include <iostream>
#include <vector>

using namespace std;

// Khai báo class GameScript
class GameScript;

// Hàm main
int main() {
    GameScript game;
    bool gameRunning = true;

    while (gameRunning) {
         if (gameMode == "1player")
            player2Name.text = "Computer";
        else
            player2Name.text = "2nd Player";

        Turn = Seed.CROSS;

        Instructions.text = "Turn: 1st Player";

        for (int i = 0; i < 9; i++)
            player[i] = Seed.EMPTY;
            
        Spawn();

        if (game.Won(GameScript::CROSS) || game.Won(GameScript::NOUGHT) || game.IsDraw()) {
            gameRunning = false;
        }
    }

    return 0;
}

class GameScript {
public:
    enum Seed { EMPTY, CROSS, NOUGHT };

    string gameMode;
    vector<Seed> player;
    Seed Turn;
    vector<vector<int>> allConditions = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    pair<float, float> pos1, pos2;

    // Constructor
    GameScript() {
        player.resize(9, EMPTY);
        Turn = CROSS;
    }

    void Spawn(Seed turn, int id);
    bool Won(Seed currPlayer);
    bool IsDraw();
    pair<float, float> calculateCenter();
    float calculateSlope();
    int minimax(Seed currPlayer, vector<Seed>& board, int alpha, int beta);
};
// Định nghĩa các hàm trong class GameScript
void GameScript::Spawn(Seed turn, int id) {
    player[id] = turn;
    if (Won(turn)) {
        cout << "Player " << (turn == CROSS ? "1" : "2") << " has won!!!" << endl;
        // Spawn bar
        float slope = calculateSlope();
        // Instantiate(bar, calculateCenter(), Quaternion.Euler(0, 0, slope));
    } else {
        Turn = (Turn == CROSS) ? NOUGHT : CROSS;
        cout << "Turn: " << ((Turn == CROSS) ? "1st Player" : "2nd Player") << endl;
    }
}

bool GameScript::Won(Seed currPlayer) {
    for (const auto& condition : allConditions) {
        if (player[condition[0]] == currPlayer &&
            player[condition[1]] == currPlayer &&
            player[condition[2]] == currPlayer) {
            // Keep track of the winning positions to spawn a Bar
            pos1 = {static_cast<float>(condition[0]), static_cast<float>(condition[1])};
            pos2 = {static_cast<float>(condition[2]), static_cast<float>(condition[2])};
            return true;
        }
    }
    return false;
}

bool GameScript::IsDraw() {
    for (int i = 0; i < 9; i++) {
        if (player[i] == EMPTY) {
            return false;
        }
    }
    return true;
}

pair<float, float> GameScript::calculateCenter() {
    float x = (pos1.first + pos2.first) / 2;
    float y = (pos1.second + pos2.second) / 2;
    return {x, y};
}

float GameScript::calculateSlope() {
    float slope;
    if (pos1.first == pos2.first) {
        slope = 0.0f;
    } else if (pos1.second == pos2.second) {
        slope = 90.0f;
    } else if (pos1.first > 0.0f) {
        slope = -45.0f;
    } else {
        slope = 45.0f;
    }
    return slope;
}

int GameScript::minimax(Seed currPlayer, vector<Seed>& board, int alpha, int beta) {
    if (IsDraw()) return 0;
    if (Won(NOUGHT)) return +1;
    if (Won(CROSS)) return -1;

    int score;

    if (currPlayer == NOUGHT) {
        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = NOUGHT;
                score = minimax(CROSS, board, alpha, beta);
                board[i] = EMPTY;
                if (score > alpha) alpha = score;
                if (alpha > beta) break;
            }
        }
        return alpha;
    } else {
        for (int i = 0; i < 9; i++) {
            if (board[i] == EMPTY) {
                board[i] = CROSS;
                score = minimax(NOUGHT, board, alpha, beta);
                board[i] = EMPTY;
                if (score < beta) beta = score;
                if (alpha > beta) break;
            }
        }
        return beta;
    }
}
