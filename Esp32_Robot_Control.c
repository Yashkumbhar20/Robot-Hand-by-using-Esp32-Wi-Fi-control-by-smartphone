#include <ESP8266WiFi.h>
#include <Servo.h>

const char *ssid = "Iot";           // Wi-Fi SSID
const char *password = "Iot12345";  // Wi-Fi Password

// Motor control pins
int motor1A = D1; // IN1
int motor1B = D2; // IN2
int motor2A = D3; // IN3
int motor2B = D4; // IN4

// Servo control pins
int servo1Pin = D5;
int servo2Pin = D6;
int servo3Pin = D7;
int servo4Pin = D8;

// Servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// Initialize Wi-Fi server
WiFiServer server(80);

void setup() {
  // Start serial communication
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize motor control pins
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);

  // Attach servos
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);

  // Start the web server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  // Listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    String request = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        request += c;
        if (c == '\n') {
          // If the request contains certain text, control motors and servos
          if (request.indexOf("GET /forward") != -1) {
            forward();
          } else if (request.indexOf("GET /backward") != -1) {
            backward();
          } else if (request.indexOf("GET /left") != -1) {
            left();
          } else if (request.indexOf("GET /right") != -1) {
            right();
          } else if (request.indexOf("GET /stop") != -1) {
            stopMotors();
          } else if (request.indexOf("GET /servo1_0") != -1) {
            servo1.write(0);
          } else if (request.indexOf("GET /servo1_90") != -1) {
            servo1.write(90);
          } else if (request.indexOf("GET /servo1_180") != -1) {
            servo1.write(180);
          } else if (request.indexOf("GET /servo2_0") != -1) {
            servo2.write(0);
          } else if (request.indexOf("GET /servo2_90") != -1) {
            servo2.write(90);
          } else if (request.indexOf("GET /servo2_180") != -1) {
            servo2.write(180);
          } else if (request.indexOf("GET /servo3_0") != -1) {
            servo3.write(0);
          } else if (request.indexOf("GET /servo3_90") != -1) {
            servo3.write(90);
          } else if (request.indexOf("GET /servo3_180") != -1) {
            servo3.write(180);
          } else if (request.indexOf("GET /servo4_0") != -1) {
            servo4.write(0);
          } else if (request.indexOf("GET /servo4_90") != -1) {
            servo4.write(90);
          } else if (request.indexOf("GET /servo4_180") != -1) {
            servo4.write(180);
          }

          // Send HTTP response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();

          // Send the HTML page
          client.println("<html><body><h1>Robot Control</h1>");
          client.println("<a href='/forward'>Forward</a><br>");
          client.println("<a href='/backward'>Backward</a><br>");
          client.println("<a href='/left'>Left</a><br>");
          client.println("<a href='/right'>Right</a><br>");
          client.println("<a href='/stop'>Stop</a><br>");
          client.println("<a href='/servo1_0'>Servo 1: 0°</a><br>");
          client.println("<a href='/servo1_90'>Servo 1: 90°</a><br>");
          client.println("<a href='/servo1_180'>Servo 1: 180°</a><br>");
          client.println("<a href='/servo2_0'>Servo 2: 0°</a><br>");
          client.println("<a href='/servo2_90'>Servo 2: 90°</a><br>");
          client.println("<a href='/servo2_180'>Servo 2: 180°</a><br>");
          client.println("<a href='/servo3_0'>Servo 3: 0°</a><br>");
          client.println("<a href='/servo3_90'>Servo 3: 90°</a><br>");
          client.println("<a href='/servo3_180'>Servo 3: 180°</a><br>");
          client.println("<a href='/servo4_0'>Servo 4: 0°</a><br>");
          client.println("<a href='/servo4_90'>Servo 4: 90°</a><br>");
          client.println("<a href='/servo4_180'>Servo 4: 180°</a><br>");
          client.println("</body></html>");
          break;
        }
      }
    }
    client.stop();
  }
}

void forward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void backward() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void left() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
}

void right() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
}

void stopMotors() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
}
