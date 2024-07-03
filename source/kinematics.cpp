#include "kinematics.hpp"

namespace RobKin{
    Kinematics::Kinematics(const std::vector<DHParam> &params) : dh_params(params) {};

    glm::mat4 Kinematics::dh_to_matrix(const DHParam& param)
    {
        glm::mat4 T = glm::mat4(1.0f);
        T = glm::rotate(T, static_cast<float>(param.theta), glm::vec3(0.0f, 0.0f, 1.0f));
        T = glm::translate(T, glm::vec3(param.a, 0.0f, 0.0f));
        T = glm::rotate(T, static_cast<float>(param.alpha), glm::vec3(1.0f, 0.0f, 0.0f));
        T = glm::translate(T, glm::vec3(0.0f, 0.0f, param.d));
        return T;
    }

    glm::mat4 Kinematics::forward_kin(const std::vector<long double> &joint_angles)
    {
        glm::mat4 T = glm::mat4(1.0f);

        for (size_t i = 0; i < dh_params.size(); ++i) {
            DHParam param = dh_params[i];
            param.theta = joint_angles[i];
            T *= dh_to_matrix(param);
        }
        return T;
    }
}