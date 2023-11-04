#include <vector>
#include <queue>

using namespace std;

vector<int> Torneo(vector<int> playerSkills, int numPlayers, int numRounds) {
    queue<int> playerQueue;
    for (size_t i = 2; i < playerSkills.size(); ++i) {
        playerQueue.push(playerSkills[i]);
    }

    int wins = 0;
    int currentPlayer = playerSkills[0];
    int challenger = playerSkills[1];

    vector<int> result(2);
    for (int round = 1; round <= numRounds; ++round) {
        if (currentPlayer > challenger) {
            wins++;
            result = {challenger, currentPlayer};
            playerQueue.push(challenger);
        } else {
            wins = 1;
            result = {currentPlayer, challenger};
            playerQueue.push(currentPlayer);
            currentPlayer = challenger;
        }

        challenger = playerQueue.front();
        playerQueue.pop();
    }

    return result;
}
