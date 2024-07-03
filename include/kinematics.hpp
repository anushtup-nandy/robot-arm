#ifndef AN_ROB_KIN_
#define AN_ROB_KIN_

#include <Eigen/Dense>
#include <cmath>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
namespace RobKin{
	struct DHParam{
		long double a; // link length
        long double alpha; //link twist
        long double d; //link offset
        long double theta; //Joint angle
	};
	class Kinematics{
		private:
			std::vector<DHParam> dh_params;
		public:
			Kinematics(const std::vector<DHParam> &params); 
			
			virtual glm::mat4 dh_to_matrix(const DHParam &param);

			virtual glm::mat4 forward_kin(const std::vector<long double> &joint_angles);

			// virtual std::vector<long> inverse_kin(const glm::mat4 &desiredPose);
	};
	
}

#endif
