// Segment pins: A to G, DP
const int segmentPins[] = {9, 8, 7, 6, 5, 4, 3, 2}; // A-G, DP
const int digitPins[] = {1, 0}; // Digit 1 (tens), Digit 2 (ones)

// Segment state for digits 0-9 (A to G)
const byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(segmentPins[i], OUTPUT);
    digitalWrite(segmentPins[i], LOW); // Turn OFF segments (common cathode)
  }

  for (int i = 0; i < 2; i++) {
    pinMode(digitPins[i], OUTPUT);
    digitalWrite(digitPins[i], LOW); // Turn OFF digits (common cathode)
  }
}

void loop() {
  for (int i = 0; i <= 99; i++) {
    int tens = i / 10;
    int ones = i % 10;

    unsigned long start = millis();
    while (millis() - start < 500) { // Hold each number for 500ms
      // Show ones digit (right) first
      displayDigit(ones, 1);
      delay(5);
      // Then show tens digit (left)
      displayDigit(tens, 0);
      delay(5);
    }
  }
}

void displayDigit(int num, int pos) {
  // Turn off both digits (common cathode = HIGH to turn off)
  digitalWrite(digitPins[0], HIGH);
  digitalWrite(digitPins[1], HIGH);

  // Set segment states (common cathode: HIGH = ON)
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i] ? HIGH : LOW);
  }

  // DP (optional): OFF
  digitalWrite(segmentPins[7], LOW); // DP off

  // Enable selected digit (common cathode: LOW to enable)
  digitalWrite(digitPins[pos], LOW);
}
