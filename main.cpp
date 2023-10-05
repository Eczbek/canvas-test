#include <bits/stdc++.h>
#include <xieite/xieite.hpp>

int main() {
	xieite::graphics::Canvas canvas = xieite::graphics::Canvas(xieite::geometry::Point(0, 0), xieite::geometry::Point(20, 15));
	canvas.controller.setInputEcho(false);
	canvas.controller.setInputSignals(false);

	xieite::geometry::Polygon poly = xieite::geometry::Polygon(std::vector<xieite::geometry::Point> {
		xieite::geometry::Point(4, 7),
		xieite::geometry::Point(-3, 5),
		xieite::geometry::Point(-8, -9),
		xieite::geometry::Point(6, -2)
	});

	double rotation = 0;
	double rotationSpeed = 0;
	double scale = 1;
	double movementSpeed = 0;
	bool movement = false;
	while (true) {
		canvas.clear();
		canvas.draw(xieite::geometry::scale(xieite::geometry::rotate(poly, rotation, canvas.center), scale, canvas.center), xieite::graphics::Color(0, 0, 0));
		canvas.draw(canvas.center, xieite::graphics::Color(255, 0, 0));
		canvas.print(xieite::streams::Position(0, 0));
		std::flush(canvas.controller.outputStream);
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		const std::string input = canvas.controller.readString();
		if (input.contains('q')) {
			break;
		}
		if (input.contains('w')) {
			movement = !movement;
		}
		if (input.contains('z')) {
			scale += 0.1;
		}
		if (input.contains('x')) {
			scale -= 0.1;
		}
		if (input.contains('d')) {
			rotationSpeed += 0.1;
		}
		if (input.contains('a')) {
			rotationSpeed -= 0.1;
		}
		if (movement) {
			++movementSpeed;
		}
		rotationSpeed *= 0.8;
		movementSpeed *= 0.8;
		rotation += rotationSpeed;
		canvas.center = xieite::geometry::rotate(xieite::geometry::Point(canvas.center.x, canvas.center.y + movementSpeed), -rotation, canvas.center);
	}
}
