#include<iostream>
#include<raylib.h>
#include<deque>
#include<raymath.h>

int cellCount{ 20 };
int cellSize{ 40 };
float offset{ 75 };
int score{ 0 };

Color green{ 173,204,96,255 };
Color darkGreen{ 43,51,24,255 };

double totalUpdateTime = 0;

bool EventTriggerInterval(double interval) {

	if (GetTime() - totalUpdateTime >= interval)
	{
		totalUpdateTime = GetTime();
		return true;
	}
	return false;
}

bool CollidingWithSnake(std::deque<Vector2> snake, Vector2 food) {

	for (size_t i = 0; i < snake.size(); i++)
	{
		if (Vector2Equals(snake[i], food))
		{
			return true;
		}
	}
	
	return false;
}

class Food {

	Texture2D m_Texture;
	Vector2 m_Position;

public:

	Food() {

		Image imgBuffer = LoadImage("food.png");
		
		m_Texture = LoadTextureFromImage(imgBuffer);
		UnloadImage(imgBuffer);

		m_Position = GenerateRandomCell();
	}

	void SetRandomPosition(std::deque<Vector2> snakeBody) {
		m_Position = GenerateRandomPos(snakeBody);
	}

	void Draw() {

		DrawTexture(m_Texture, offset + m_Position.x * cellSize, offset + m_Position.y * cellSize, WHITE);
	}

	bool SnakeCollision(std::deque< Vector2> snakeBody) {

		if (Vector2Equals(snakeBody[0], m_Position))
		{
			m_Position = GenerateRandomPos(snakeBody);
			return true;
		}

		return false;
	}

	Vector2 GenerateRandomCell() {

		float x = GetRandomValue(0, cellCount - 1);
		float y = GetRandomValue(0, cellCount - 1);
		return { x,y };
	}

	Vector2 GenerateRandomPos(std::deque<Vector2> snakeBody) {
		Vector2 pos = GenerateRandomCell();

		while (CollidingWithSnake(snakeBody, pos))
		{
			pos = GenerateRandomCell();
		}

		return pos;
	}

	~Food() {

		UnloadTexture(m_Texture);
	}
};

class Snake {

public:
	std::deque<Vector2> body{ Vector2{6,9}, Vector2{7,9},Vector2{8,9} };
	Vector2 direction{ 1,0 };

	void Draw() {
		for (size_t i = 0; i < body.size(); i++)
		{
			Rectangle rect{ offset + body[i].x * cellSize, offset + body[i].y * cellSize, cellSize, cellSize };
			DrawRectangleRounded(rect, 0.5, 6, darkGreen);
		}
	}

	void Update() {
		body.pop_back();
		Increment();
	}

	void Increment() {
		body.push_front(Vector2Add(body[0], direction));
	}

	void GameOver() {
		body = { Vector2{ 6,9 }, Vector2{ 7,9 }, Vector2{ 8,9 } };
		direction = { 1,0 };
	}
};

class Game {

public: 
	Food bug;
	Snake snake;
	Sound eatSound, wallSound;

	bool isRunning{ false };

	Game() {
		InitAudioDevice();
		eatSound = LoadSound("eat.mp3");
		wallSound = LoadSound("wall.mp3");
	}

	void Draw() {

		bug.Draw();
		snake.Draw();
	}

	void Update() {

		if (!isRunning)
		{
			return;
		}

		// Update
		if (EventTriggerInterval(0.2))
		{
			snake.Update();
			if (bug.SnakeCollision(snake.body))
			{
				PlaySound(eatSound);
				snake.Increment();
				score++;
			}
		}

		CheckCollisionWithEdges();
		SnakeSelfCollision();
	}

	void CheckCollisionWithEdges() {
		if (snake.body[0].x == cellCount || snake.body[0].x == -1)
		{
			snake.GameOver();
			bug.SetRandomPosition(snake.body);
			isRunning = false;
			score = { 0 };
			PlaySound(wallSound);
		}

		if (snake.body[0].y == cellCount || snake.body[0].y == -1)
		{
			snake.GameOver();
			bug.SetRandomPosition(snake.body);
			isRunning = false;
			score = { 0 };
			PlaySound(wallSound);
		}
	}

	void SnakeSelfCollision() {
		for (size_t i = 0; i < snake.body.size() - 1; i++)
		{
			if (Vector2Equals(snake.body[0], snake.body[i + 1])) {

				snake.GameOver();
				bug.SetRandomPosition(snake.body);
				isRunning = false;
				score = { 0 };
				PlaySound(wallSound);
			}
		}
	}

	~Game() {
		UnloadSound(eatSound);
		UnloadSound(wallSound);
		CloseAudioDevice();
	}
};

int main() {

	InitWindow((2 * offset) + cellCount * cellSize, (2 * offset) + cellCount * cellSize, "Snake Game");
	SetTargetFPS(60);

	Game snakeGame;

	while (!WindowShouldClose())
	{
		// Event Processing
		if (IsKeyPressed(KEY_W) && (snakeGame.snake.direction.y != 1)) {
			snakeGame.snake.direction = { 0,-1 };
			snakeGame.isRunning = true; 
		}
		
		if (IsKeyPressed(KEY_S) && (snakeGame.snake.direction.y != -1))
		{
			snakeGame.snake.direction = { 0,1 };
			snakeGame.isRunning = true;
		}
		
		if (IsKeyPressed(KEY_A) && (snakeGame.snake.direction.x != 1))
		{
			snakeGame.snake.direction = { -1,0 };
			snakeGame.isRunning = true;
		}
		
		if (IsKeyPressed(KEY_D) && (snakeGame.snake.direction.x != -1))
		{
			snakeGame.snake.direction = { 1,0 };
			snakeGame.isRunning = true;
		}

		snakeGame.Update();

		// Drawing
		ClearBackground(green);
		BeginDrawing();

		DrawText("Retro Snake Game", 70, 30, 35, darkGreen);

		DrawText(TextFormat( "Score: %i", score), GetScreenWidth() - 300, 30, 35, darkGreen);

		DrawRectangleLinesEx(Rectangle{ offset - 5, offset - 5, (float)cellSize * cellCount+ 10, (float)cellSize * cellCount + 10 },
							5, darkGreen);
		snakeGame.Draw();

		EndDrawing();
	}

	CloseWindow();
	return 0;
}