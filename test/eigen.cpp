#include <iostream>
#include <Eigen/Dense>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	/*MATRIX:
	 * matrixXd means dynamic matrix
	 * matrixCf means fixed matrix (compile time)
	 * */
	Eigen::MatrixXd m(2, 2);
	Eigen::MatrixXd m2(2, 2);
	Eigen::Vector3d v(1,2,3);
	Eigen::Vector3d w(0,1,2);	
	
	std::ptrdiff_t i, j;
	std::ptrdiff_t i2, j2;
	
	m(0,0) = 3;
	m(1,0) = 2.5;
	m(0,1) = -1;
	m(1,1) = m(1,0) + m(0,1);
	
	m2(0, 0) = 1;
	m2(1, 0) = 1;
	m2(0, 1) = 1;
	m2(1, 1) = 1;
	
	/*   std::cout << m << std::endl; */
	std::cout<<"sum : "<<m.sum()<<std::endl;
	std::cout<<"product :  "<< m.prod()<< std::endl;
	std::cout<<"min and max coeff : "<< m.minCoeff(&i, &j) <<
		" at ("<< i<< j << ")" <<" and "<< m.maxCoeff(&i2, &j2)<<" at ("<< i2<< j2 << ")" << std::endl;
	//similarly transpose, conjugate and adjoint also exist:
	std::cout<<"Transpose : "<<m.transpose()<<std::endl;
	std::cout<<"Conjugate : "<<m.conjugate()<<std::endl;
	std::cout<<"Adjoint : "<<m.adjoint()<<std::endl;

	//mult:
	std::cout<<"matrix x matrix : "<< m*m2<<std::endl;
	std::cout<<"dot : "<<v.dot(w)<<std::endl;
	std::cout<<"cross : "<< v.cross(w)<<std::endl;

	/*ARRAY:
	 *
	 * General purpose array, not similar to matrix. 
	 * Only for non-linear algebra purposes
	 * Performing coefficient-wise operations
	 * Same f and d for fixed and dynamic allocations.
	 * */
	Eigen::ArrayXXf a(2,2);
 	Eigen::ArrayXXf b(2,2);
	a << 1,2,3,4;
	b << 5,6,7,8;
	std::cout << "a + b = " << std::endl << a + b << std::endl << std::endl;
	std::cout << "a * b = " << std::endl << a * b << std::endl;
	std::cout<<"matrix conversion : "<< a.matrix()*b.matrix() << std::endl;


	return 0;
}
