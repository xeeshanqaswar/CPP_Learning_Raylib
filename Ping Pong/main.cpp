#include<iostream>
#include<raylib.h>
#include<random>

int playerScore = 0;
int cpuScore = 0;

Color midnightBlue{ 20,93,160,255 };
Color blue{ 46,139,192,255 };
Color skyBlue{ 177,212,224,80 };
Color ballColor{ 250,190,36,255 };

class Ball {

	Vector2 position;

public:

	Vector2 speed{ 7,7 };
	float radius;

	Ball(Vector2 p, float r) : position{ p }, radius{ r } {};

	const Vector2 GetPosition() { return position; }

	void Draw() {
		DrawCircle(position.x, position.y, radius, ballColor);
	}

	void Update() {
		position.x += speed.x;
		position.y += speed.y;

		if ((position.x + radius) >= GetScreenWidth() )
		{
			playerScore++;
			Reset();
		}

		if ((position.x + radius) <= 0)
		{
			cpuScore++;
			Reset();
		}

		if ((position.y + radius) >= GetScreenHeight() || (position.y + radius) <= 0)
		{
			speed.y *= -1;
		}
	};

	void Reset() {
		position.x = GetScreenWidth() / 2;
		position.y = GetScreenHeight() / 2;

		int directions[]{ -1,1 };
		speed.x *= directions[GetRandomValue(0, 1)];
		speed.y *= directions[GetRandomValue(0, 1)];
	}
};

class Paddle {

protected:
	Vector2 position;
	float speed = 10;
	Vector2 size;

public:

	Paddle(Vector2 p, Vector2 s) : position{ p }, size{ s } {};

	const Vector2 GetPosition() {
		return position;
	}

	const Vector2 GetSize() {
		return size;
	}

	void Draw() {
		Rectangle pRect{ position.x, position.y, size.x, size.y };
		DrawRectangleRounded(pRect, 0.8, 0, WHITE);
	}

	void Update() {

		if (IsKeyDown(KEY_UP))
		{
			position.y -= speed;
		}
		
		if (IsKeyDown(KEY_DOWN))
		{
			position.y += speed;
		}

		if ((position.y + size.y) >= GetScreenHeight())
		{
			position.y = GetScreenHeight() - size.y;
		}
		 
		if (position.y < 0)
		{
			position.y = 0;
		}
	}
};

class PaddleAI : public Paddle {

public:

	PaddleAI(Vector2 p, Vector2 s) : Paddle(p, s) {};

	void Update(Ball ball) {

		if (ball.GetPosition().y < (position.y + (size.y / 2)))
		{
			position.y -= speed;
		}

		if (ball.GetPosition().y > (position.y + (size.y / 2)))
		{
			position.y += speed;
		}

		if ((position.y + size.y) >= GetScreenHeight())
		{
			position.y = GetScreenHeight() - size.y;
		}

		if (position.y < 0)
		{
			position.y = 0;
		}
	}
};

int main() {

	const int screenWidth = 1280;
	const int screenHeight = 800;
	const Vector2 paddleSize = Vector2{ 25, 120 };
	const int padding = 10;
	
	Ball ball(Vector2{ screenWidth / 2, screenHeight / 2 }, 20); 
	Paddle paddle1(Vector2{ padding, (screenHeight - paddleSize.y) / 2 }, paddleSize);
	PaddleAI paddle2(Vector2{ screenWidth - (padding + paddleSize.x),  (screenHeight - paddleSize.y) / 2 }, paddleSize);

	InitWindow(screenWidth, screenHeight, "Ping Pong");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		// Update Data
		ball.Update();
		paddle1.Update();
		paddle2.Update(ball);

		// Check for Collision
		Rectangle playerCollider = Rectangle{ paddle1.GetPosition().x, paddle1.GetPosition().y, paddle1.GetSize().x,paddle1.GetSize().y };
		Rectangle cpuCollider = Rectangle{ paddle2.GetPosition().x, paddle2.GetPosition().y, paddle2.GetSize().x,paddle2.GetSize().y };
		bool checkPlayerCollision = CheckCollisionCircleRec(ball.GetPosition(), ball.radius, playerCollider);
		bool checkCpuCollision = CheckCollisionCircleRec(ball.GetPosition(), ball.radius, cpuCollider);

		if (checkPlayerCollision || checkCpuCollision)
		{
			ball.speed.x *= -1;
		}


		// Drawing
		ClearBackground(midnightBlue);
		BeginDrawing();

		DrawRectangle(0, 0, GetScreenWidth() / 2, GetScreenHeight(), blue);
		DrawCircle(GetScreenWidth() / 2, GetScreenHeight() / 2, 200, skyBlue);
		DrawLine(GetScreenWidth() / 2, 0, GetScreenWidth() / 2, GetScreenHeight(), WHITE);

		ball.Draw();
		paddle1.Draw();
		paddle2.Draw();
		
		DrawText(TextFormat("%i", playerScore), GetScreenWidth() / 4 - 40, 20, 80, WHITE);
		DrawText(TextFormat("%i", cpuScore), 3*(GetScreenWidth() / 4), 20, 80, WHITE);


		EndDrawing();
	}
	
	CloseWindow();

	return 0;
}

