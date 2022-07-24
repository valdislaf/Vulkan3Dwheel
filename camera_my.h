#pragma once
#include <glm/fwd.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/quaternion.hpp>


enum CameraType
{
	LookAt,
	FirstPerson
};


class camera_my
{
	public:
		void update(float deltaTime);

		// Update camera passing separate axis data (gamepad)
		// Returns true if view or position has been changed
		bool update_gamepad(glm::vec2 axis_left, glm::vec2 axis_right, float delta_time);

		CameraType type = CameraType::LookAt;

		glm::vec3 rotation = glm::vec3();
		glm::vec3 position = glm::vec3();

		float rotation_speed = 1.0f;
		float translation_speed = 1.0f;

		bool updated = false;

		struct
		{
			glm::mat4 perspective;
			glm::mat4 view;
		} matrices;

		struct
		{
			bool left = false;
			bool right = false;
			bool up = false;
			bool down = false;
		} keys;

		bool moving();

		float get_near_clip();

		float get_far_clip();

		void set_perspective(float fov, float aspect, float znear, float zfar);

		void update_aspect_ratio(float aspect);

		void set_position(const glm::vec3& position);

		void set_rotation(const glm::vec3& rotation);

		void rotate(const glm::vec3& delta);

		void set_translation(const glm::vec3& translation);

		void translate(const glm::vec3& delta);

	private:

		float fov;
		float znear, zfar;

		void update_view_matrix();

};
