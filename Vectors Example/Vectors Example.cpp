#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>

// Parameters for the score distribution
const int SCORE_COUNT = 150;
const int SCORE_MAX = 100;
const int SCORE_MIN = 0;
const int SCORE_MEAN = 70;
const int SCORE_DEV = 10;
// Use this to seed the random number generator so it's mostly unpredictable.
const unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

// Random number generation mechanisms. 
std::default_random_engine generator(seed);
std::normal_distribution<float> dist(SCORE_MEAN, SCORE_DEV);

// Helper functions (I couldn't be bothered to put them in a separate file). 
int generateScore();
void displayScores(const std::vector<int> scores);

int main()
{
    // Create a series of randomised test scores
    std::vector<int> scores;
    for (int i = 0; i < SCORE_COUNT; i++) {
        scores.push_back(generateScore());
    }
    // Display the scores
    std::cout << "Scores (un-sorted): " << std::endl;
    displayScores(scores);

    // Calculate the mean with an old-style for loop
    float mean = scores.at(0);
    for (int i = 1; i < scores.size(); i++)
    {
        mean = (mean + scores.at(i)) / 2; // Incremental mean formula
    }
    std::cout << "Mean: " << mean << std::endl; 

    // Calculate the mean using a new-style loop for interables. These are 
    // really useful if you just want to iterate over everything in the 
    // vector.
    int maxScore = SCORE_MIN - 1;
    int minScore = SCORE_MAX + 1;
    for (const int score : scores)
    {
        // More compact if-then-else
        maxScore = score > maxScore ? score : maxScore;
        minScore = score < minScore ? score : minScore;
    }
    std::cout << "Max & Min: " << maxScore << ", " << minScore << std::endl;

    // Sort the scores using the standard library. This is done in-place.
    std::sort(scores.begin(), scores.end());
    std::cout << "Scores (sorted): " << std::endl;
    displayScores(scores);

    // Calculate the mode now that the scores are sorted
    int mode;
    int mode_idx = scores.size() / 2;
    if (scores.size() % 2 == 0) {
        // Even number of scores, mode is average of two middle values
        mode = (scores.at(mode_idx) + scores.at(mode_idx + 1)) / 2;
    } else {
        // Odd number of scores, mode is the true middle value
        mode = (scores.at(mode_idx));
    }
    std::cout << "Mode: " << mode << std::endl;

    // Sort the scores according to grade bands
    int fail = 0;
    int pass = 0; 
    int credit = 0;
    int distinction = 0;
    int highDistinction = 0;
    const int MIN_PASS = 50;
    const int MIN_CRED = 65;
    const int MIN_DIST = 75;
    const int MIN_HDIS = 85;
    for (const int score : scores) {
        if (score < MIN_PASS) {
            fail++;
            continue;
        }
        if (score < MIN_CRED) {
            pass++;
            continue;
        }
        if (score < MIN_DIST) {
            credit++;
            continue;
        }
        if (score < MIN_HDIS) {
            distinction++;
            continue;
        }
        // If a score gets to this point, it must be HD
        highDistinction++;
    }
    std::cout << "Grades: " << std::endl;
    std::cout << "Fail: " << fail << std::endl;
    std::cout << "Pass: " << pass << std::endl;
    std::cout << "Credit: " << credit << std::endl;
    std::cout << "Distinction: " << distinction << std::endl;
    std::cout << "High Distinction: " << highDistinction << std::endl;
    return EXIT_SUCCESS;
}

int generateScore() {
    // Generate the score
    int score = static_cast<int>(dist(generator));
    // Since the normal distribution isn't clamped, it might generate values 
    // above outside 0-100, so we need to make sure we clamp the value. 
    score = (score < 0) ? 0 : score;
    score = (score > 100) ? 100 : score; // This is a compact if-then-else
    /* For clarity, here's the equivalent full code:
    if (score > 100) {
        return 100
    } else {
        return score
    }
    */
    return score;
}

// Note that we qualify scores with const. It's a good idea to put const if 
// your function doesn't modify anything, as it makes it clear to people
// using the function, and it helps the compiler to optimise.
void displayScores(const std::vector<int> scores) {
    const int GROUP_SIZE = 15;
    for (int i = 0; i < scores.size(); i++)
    {
        // Print the score
        std::cout << scores.at(i) << " ";
        // When we reach the end of a group, add a new line
        if (i % GROUP_SIZE == (GROUP_SIZE - 1)) {
            std::cout << std::endl;
        }
    }
}
