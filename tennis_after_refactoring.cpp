#include <string>
using std::string;

class Tennis {
public:
	const string tennis_score(int p1Score, int p2Score) {
		if (isDeuce(p1Score, p2Score)) return "Deuce";
		if (isSamePoint(p1Score, p2Score)) return convertScoreToString(p1Score) + "-All";
		if (isWinForPlayer1(p1Score, p2Score)) return "Win for player1";
		if (isWinForPlayer2(p1Score, p2Score)) return "Win for player2";
		if (isAdvantageForPlayer1(p1Score, p2Score)) return "Advantage player1";
		if (isAdvantageForPlayer2(p1Score, p2Score)) return "Advantage player2";

		return convertScoreToString(p1Score) + "-" + convertScoreToString(p2Score);
	}

	bool isDeuce(int p1Score, int p2Score) {
		return p1Score == p2Score && p1Score >= 3;
	}
	bool isSamePoint(int p1Score, int p2Score) {
		return p1Score == p2Score;
	}
	bool isWinForPlayer1(int p1Score, int p2Score) {
		return p1Score >= 4 && p1Score >= p2Score + 2;
	}
	bool isWinForPlayer2(int p1Score, int p2Score) {
		return p2Score >= 4 && p2Score >= p1Score + 2;
	}
	bool isAdvantageForPlayer1(int p1Score, int p2Score) {
		return p1Score >= 4 && p1Score == p2Score + 1;
	}
	bool isAdvantageForPlayer2(int p1Score, int p2Score) {
		return p2Score >= 4 && p2Score == p1Score + 1;
	}

	string convertScoreToString(int score) {
		if (score == 0) return "Love";
		if (score == 1) return "Fifteen";
		if (score == 2) return "Thirty";
		if (score == 3) return "Forty";
	}
};
