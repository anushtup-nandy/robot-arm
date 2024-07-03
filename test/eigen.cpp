#include <iostream>
#include "kinematics.hpp"

int main() {
    // Define DH parameters for a 6DOF robot arm
   	std::vector<RobKin::DHParam> dh_params = {
        {0.0, (M_PI / 2), 0.1, 0.0},
        {0.3, 0.0, 0.0, 0.0},
        {0.2, (M_PI / 2), 0.0, 0.0},
        {0.0, (-M_PI / 2), 0.4, 0.0},
        {0.0, (M_PI / 2), 0.0, 0.0},
        {0.0, 0.0, 0.2, 0.0}
    };

    RobKin::Kinematics robot(dh_params);

    // Example joint angles
	std::vector<long double> joint_angles = {0.0, M_PI / 4, 0.0, M_PI / 6, 0.0, M_PI / 3};
    // Perform forward kinematics
    glm::mat4 end_effector_pose = robot.forward_kin(joint_angles);

    // Print the resulting end-effector pose
    std::cout << "End-Effector Pose:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << end_effector_pose[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}