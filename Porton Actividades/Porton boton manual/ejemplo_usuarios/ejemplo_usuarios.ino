#include <EEPROM.h>

#define MAX_USERS 10
#define USERNAME_MAX_LEN 16
#define PASSWORD_MAX_LEN 16

typedef struct {
  char username[USERNAME_MAX_LEN];
  char password[PASSWORD_MAX_LEN];
} User;

User users[MAX_USERS];

int getFirstFreeUserIndex() {
  for (int i = 0; i < MAX_USERS; i++) {
    if (users[i].username[0] == '\0') {
      return i;
    }
  }
  return -1;
}

void setup() {
  Serial.begin(9600);

  // Initialize all users to empty
  for (int i = 0; i < MAX_USERS; i++) {
    memset(users[i].username, 0, sizeof(users[i].username));
    memset(users[i].password, 0, sizeof(users[i].password));
  }

  // Load existing users from EEPROM
  int userIndex = 0;
  while (userIndex < MAX_USERS) {
    if (EEPROM.read(userIndex) == 1) {
      int start = (userIndex + 1) * sizeof(User);
      int end = start + sizeof(User);
      EEPROM.get(start, users[userIndex]);
      userIndex++;
    } else {
      userIndex += sizeof(User) / sizeof(EEPROM.get(0, users[0]));
    }
  }
}

void loop() {
  if (Serial.available() >= (USERNAME_MAX_LEN + PASSWORD_MAX_LEN + 1)) {
    String input = Serial.readStringUntil('\n');
    int spaceIndex = input.indexOf(' ');
    if (spaceIndex == -1) {
      Serial.println("Invalid input");
      return;
    }
    String username = input.substring(0, spaceIndex);
    String password = input.substring(spaceIndex + 1);
    if (username.length() == 0 || password.length() == 0) {
      Serial.println("Invalid input");
      return;
    }
    if (getFirstFreeUserIndex() == -1) {
      Serial.println("Max number of users reached");
      return;
    }
    strcpy(users[getFirstFreeUserIndex()].username, username.c_str());
    strcpy(users[getFirstFreeUserIndex()].password, password.c_str());
    int start = (getFirstFreeUserIndex() + 1) * sizeof(User);
    EEPROM.put(start, users[getFirstFreeUserIndex()]);
    EEPROM.write(start / sizeof(User) - 1, 1);
    Serial.print("User added: ");
    Serial.println(username);
  }
}