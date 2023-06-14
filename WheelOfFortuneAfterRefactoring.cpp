#include <string>
#include <vector>

using namespace std;

const int TRY_COUNT_LIMIT = 26;
const int MAX_LINE_COUNT = 5;

struct Node {
	int x, y;
};

class Wheel {
public:
	int getTotalPrice(vector<string> strs, string userdata) {
		int result = 0;
		int continueCount = 0;
		bool firstChance[MAX_LINE_COUNT] = { false };
		bool secondChance[MAX_LINE_COUNT] = { false };

		for (int i = 0; i < TRY_COUNT_LIMIT; i++) {
			char tryChar = userdata[i];
			vector<Node> axis = getAxisForTargetChar(strs, tryChar);

			int passCnt = axis.size();
			if (!passCnt)
			{
				clearMetadata(continueCount, secondChance);
				continue;
			}
			continueCount++;

			result += get2000Dollar(axis, secondChance);
			result += get1000Dollar(axis, firstChance, secondChance);
			result += get100Dollar(continueCount, passCnt);

			flipCard(strs, axis);
		}

		return result;
	}

private:
	vector<Node> getAxisForTargetChar(const vector<string>& strs, char tryChar) {
		vector<Node> result;

		for (int y = 0; y < strs.size(); y++) {
			for (int x = 0; x < strs[y].size(); x++) {
				if (strs[y][x] != tryChar) continue;
				result.push_back({ x, y });
			}
		}
		return result;
	}

	int get2000Dollar(vector<Node> targetAxis, bool secondChance[5]) {
		int result = 0;

		for (Node axis : targetAxis) {
			int y = axis.y;
			int x = axis.x;
			if (secondChance[y] == false) continue;
			secondChance[y] = false;
			result += 2000;
		}

		for (int i = 0; i < 5; i++) {
			secondChance[i] = false;
		}

		return result;
	}

	int get1000Dollar(vector<Node> targetAxis, bool firstChance[], bool secondChance[]) {
		int resultPrice = 0;

		for (Node axis : targetAxis) {
			int y = axis.y;
			int x = axis.x;

			if (firstChance[y] == true) continue;
			firstChance[y] = true;
			if (x != 0) continue;
			resultPrice += 1000;
			secondChance[y] = true;
		}

		return resultPrice;
	}

	void flipCard(vector<string> strs, vector<Node> targetAxis) {
		for (Node axis : targetAxis) {
			strs[axis.y][axis.x] = '_';
		}
	}

	int get100Dollar(int conCnt, int passCnt) {
		return (conCnt * 100) * passCnt;
	}

	void clearMetadata(int& conCnt, bool secondChance[]) {
		conCnt = 0;
		memset(secondChance, false, MAX_LINE_COUNT);
	}
};
