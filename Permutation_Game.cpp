//https://codeforces.com/contest/1968/problem/D

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;
    
    while (t--) {
        int n, k, startBodya, startSasha;
        cin >> n >> k >> startBodya >> startSasha;

        // Read the permutation array
        vector<int> permutation(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> permutation[i];
        }

        vector<long long> scores(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> scores[i];
        }

        long long maxScoreBodya = 0, maxScoreSasha = 0;
        long long currentScoreBodya = 0, currentScoreSasha = 0;
        int currentPosBodya = startBodya, currentPosSasha = startSasha;

        for (int turn = 1; turn <= min(n, k); ++turn) {
            currentScoreBodya += scores[currentPosBodya];
            currentScoreSasha += scores[currentPosSasha];

            // Calculate potential maximum scores if they stay in their positions for the remaining turns
            maxScoreBodya = max(maxScoreBodya, currentScoreBodya + (k - turn) * scores[currentPosBodya]);
            maxScoreSasha = max(maxScoreSasha, currentScoreSasha + (k - turn) * scores[currentPosSasha]);

            //moving the position according to game rule.
            currentPosBodya = permutation[currentPosBodya];
            currentPosSasha = permutation[currentPosSasha];
        }

        // Determine the winner based on the maximum scores
        if (maxScoreBodya == maxScoreSasha) {
            cout << "Draw" << endl;
        } else if (maxScoreBodya > maxScoreSasha) {
            cout << "Bodya" << endl;
        } else {
            cout << "Sasha" << endl;
        }
    }

    return 0;
}

