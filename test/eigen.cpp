#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <Eigen/Dense>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// int main()
// {
// 	/*MATRIX:
// 	 * matrixXd means dynamic matrix
// 	 * matrixCf means fixed matrix (compile time)
// 	 * */
// 	Eigen::MatrixXd m(2, 2);
// 	Eigen::MatrixXd m2(2, 2);
// 	Eigen::Vector3d v(1,2,3);
// 	Eigen::Vector3d w(0,1,2);	
	
// 	std::ptrdiff_t i, j;
// 	std::ptrdiff_t i2, j2;
	
// 	m(0,0) = 3;
// 	m(1,0) = 2.5;
// 	m(0,1) = -1;
// 	m(1,1) = m(1,0) + m(0,1);
	
// 	m2(0, 0) = 1;
// 	m2(1, 0) = 1;
// 	m2(0, 1) = 1;
// 	m2(1, 1) = 1;
	
// 	/*   std::cout << m << std::endl; */
// 	std::cout<<"sum : "<<m.sum()<<std::endl;
// 	std::cout<<"product :  "<< m.prod()<< std::endl;
// 	std::cout<<"min and max coeff : "<< m.minCoeff(&i, &j) <<
// 		" at ("<< i<< j << ")" <<" and "<< m.maxCoeff(&i2, &j2)<<" at ("<< i2<< j2 << ")" << std::endl;
// 	//similarly transpose, conjugate and adjoint also exist:
// 	std::cout<<"Transpose : "<<m.transpose()<<std::endl;
// 	std::cout<<"Conjugate : "<<m.conjugate()<<std::endl;
// 	std::cout<<"Adjoint : "<<m.adjoint()<<std::endl;

// 	//mult:
// 	std::cout<<"matrix x matrix : "<< m*m2<<std::endl;
// 	std::cout<<"dot : "<<v.dot(w)<<std::endl;
// 	std::cout<<"cross : "<< v.cross(w)<<std::endl;

// 	/*ARRAY:
// 	 *
// 	 * General purpose array, not similar to matrix. 
// 	 * Only for non-linear algebra purposes
// 	 * Performing coefficient-wise operations
// 	 * Same f and d for fixed and dynamic allocations.
// 	 * */
// 	Eigen::ArrayXXf a(2,2);
//  	Eigen::ArrayXXf b(2,2);
// 	a << 1,2,3,4;
// 	b << 5,6,7,8;
// 	std::cout << "a + b = " << std::endl << a + b << std::endl << std::endl;
// 	std::cout << "a * b = " << std::endl << a * b << std::endl;
// 	std::cout<<"matrix conversion : "<< a.matrix()*b.matrix() << std::endl;

// 	return 0;
// }
	