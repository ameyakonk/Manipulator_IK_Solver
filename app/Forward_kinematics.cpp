#include "Forward_kinematics.hpp"
#include "Inverse_kinematics.hpp"
#include <cstdlib>
#include <cmath>
#include "Eigen/Core"

using std::cout;
using std::endl;

using namespace Eigen;

/**
 * @fn void solve_FK(std::vector<double>)
 * @brief
 * @param _input_joint_angles
 */
void Forward_Kinematics::solve_FK(std::vector<double> _input_joint_angles) {
  Inverse_Kinematics I;
  I.set_dh_d( { 0, 5, 10, 0, 0, 0 });
  I.set_dh_a( { 0, 0, 0, 0, 0, 0 });
  I.set_dh_alpha( { -PI / 2, PI / 2, 0, (-PI / 2), PI / 2, 0 });
  Matrix<double, 4, 4> trans_mat;
  Matrix<double, 4, 4> final_transformation_matrix;

  std::vector<double>::size_type i = 0;
  for (i = 0; i < 6; i++) {
    cout << I.get_dh_d()[i] << endl;
  }

  for (int r = 0; r < 6; r++) {
    trans_mat << cos(_input_joint_angles[i]), (-cos(I.get_dh_alpha()[i]))
        * sin(_input_joint_angles[i]), sin(I.get_dh_alpha()[i])
        * sin(_input_joint_angles[i]), I.get_dh_a()[i]
        * cos(_input_joint_angles[i]), sin(_input_joint_angles[i]), cos(
        I.get_dh_alpha()[i]) * cos(_input_joint_angles[i]), (-sin(
        I.get_dh_alpha()[i]) * cos(_input_joint_angles[i]), I.get_dh_a()[i]
        * sin(_input_joint_angles[i])), 0, sin(I.get_dh_alpha()[i]), cos(
        I.get_dh_alpha()[i]), I.get_dh_d()[i], 0, 0, 0, 1;
    final_transformation_matrix *= trans_mat;
    i++;
  }

  std::vector<double> end_effector_coordinates;
  end_effector_coordinates.push_back(final_transformation_matrix(1, 4));
  end_effector_coordinates.push_back(final_transformation_matrix(2, 4));
  end_effector_coordinates.push_back(final_transformation_matrix(3, 4));
  set_output_coordinates(end_effector_coordinates);
}
/**
 * @fn void set_output_coordinates(std::vector<double>)
 * @brief
 *
 * @param _output_joint_coordinates
 */
void Forward_Kinematics::set_output_coordinates(
    std::vector<double> _output_joint_coordinates) {
  output_joint_coordinates = _output_joint_coordinates;
}
/**
 * @fn void set_output_angles(std::vector<double>)
 * @brief
 *
 * @param _output_joint_angles
 */
void Forward_Kinematics::set_output_angles(
    std::vector<double> _output_joint_angles) {
  output_joint_angles = _output_joint_angles;
}
/**
 * @fn void set_input_angles(std::vector<double>)
 * @brief
 *
 * @param _input_joint_angles
 */
void Forward_Kinematics::set_input_angles(
    std::vector<double> _input_joint_angles) {
  input_joint_angles = _input_joint_angles;
}
/**
 * @fn void set_current_pose(std::vector<double>)
 * @brief
 *
 * @param _current_robot_pose
 */
void Forward_Kinematics::set_current_pose(
    std::vector<double> _current_robot_pose) {
  current_robot_pose = _current_robot_pose;
}
/**
 * @fn std::vector<double> get_output_coordinates()
 * @brief
 *
 * @return
 */
std::vector<double> Forward_Kinematics::get_output_coordinates() {
  return output_joint_coordinates;
}
/**
 * @fn std::vector<double> get_output_angles()
 * @brief
 *
 * @return
 */
std::vector<double> Forward_Kinematics::get_output_angles() {
  return output_joint_angles;
}
/**
 * @fn std::vector<double> get_current_pose()
 * @brief
 *
 * @return
 */
std::vector<double> Forward_Kinematics::get_current_pose() {
  return current_robot_pose;
}
/**
 * @fn std::vector<double> get_input_angles()
 * @brief
 *
 * @return
 */
std::vector<double> Forward_Kinematics::get_input_angles() {
  return input_joint_angles;
}
