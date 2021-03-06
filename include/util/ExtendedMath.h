#pragma once

#include "../root/Root.h"

namespace em
{
	/**
	 * @brief Class realizing matrix operations
	 *
	 * @tparam T Type of values stored in the matrix
	 */
	template <typename T>
	class Matrix4
	{
	public:
		/**
		 * Default constructor
		 * 
		 * By default, it is initialised with identity matrix.
		 */
		Matrix4();

		/**
		 * @brief Constructor setting particular elements of the matrix
		 *
		 * @param a00 Element of index i=0 j=0
		 * @param a01 Element of index i=0 j=1
		 * @param a02 Element of index i=0 j=2
		 * @param a03 Element of index i=0 j=3
		 * @param a10 Element of index i=1 j=0
		 * @param a11 Element of index i=1 j=1
		 * @param a12 Element of index i=1 j=2
		 * @param a13 Element of index i=1 j=3
		 * @param a20 Element of index i=2 j=0
		 * @param a21 Element of index i=2 j=1
		 * @param a22 Element of index i=2 j=2
		 * @param a23 Element of index i=2 j=3
		 * @param a30 Element of index i=3 j=0
		 * @param a31 Element of index i=3 j=1
		 * @param a32 Element of index i=3 j=2
		 * @param a33 Element of index i=3 j=3
		 */
		explicit Matrix4(	T a00, T a01, T a02, T a03,
							T a10, T a11, T a12, T a13,
							T a20, T a21, T a22, T a23,
							T a30, T a31, T a32, T a33 );

		/**
		 * @brief Copy constructor and type cast
		 *
		 * @param matrix The copied matrix of type U
		 *
		 * @tparam U Type of the copied matrix
		 */
		template <typename U>
		explicit Matrix4(const Matrix4<U> &matrix);

		/**
		 * @brief Array index operator.
		 *
		 * @param index The index of the matrix
		 *
		 * @return The column / element of the matrix
		 */
		T *operator[](const unsigned &index);

		/**
		 * @brief Const array index operator
		 *
		 * @param index The index of the matrix
		 *
		 * @return The column / element of the matrix
		 */
		const T *operator[](const unsigned &index) const;

		/**
		 * @brief Negation operator
		 *
		 * @return Inverted matrix
		 */
		Matrix4<T> operator-() const;

		/**
		 * @brief Multiplication operator.
		 *
		 * @param right The right side of the operation
		 *
		 * @return The result of the multiplication
		 */
		Matrix4<T> operator*(const Matrix4<T> &right) const;

		/**
		 * @brief Addition operator.
		 *
		 * @param right The right side of the operation
		 *
		 * @return The result of the addition
		 */
		Matrix4<T> operator+(const Matrix4<T> &right) const;

		/**
		 * @brief Subtraction operator.
		 *
		 * @param right The right side of the operation
		 *
		 * @return The result of the subtraction
		 */
		Matrix4<T> operator-(const Matrix4<T> &right) const;

		/**
		 * @brief Multiplication assignment operator.
		 *
		 * @param right The right side of the multiplication assignment
		 *
		 * @return The result of the multiplication assignment
		 */
		Matrix4<T> &operator*=(const Matrix4<T> &right);

		/**
		 * @brief Addition assignment operator.
		 *
		 * @param right The right side of the addition assignment
		 *
		 * @return The result of the addition assignment
		 */
		Matrix4<T> &operator+=(const Matrix4<T> &right);

		/**
		 * @brief Subtraction assignment operator.
		 *
		 * @param right The right side of the subtraction assignment
		 *
		 * @return The result of the subtraction assignment
		 */
		Matrix4<T> &operator-=(const Matrix4<T> &right);

		/**
		 * @brief Inequality operator.
		 *
		 * @param right The right side of the inequality operator
		 *
		 * @return True if matrices are not the same, false otherwise
		 */
		const bool operator!=(const Matrix4<T> &right) const;

		/**
		 * @brief Equality operator.
		 *
		 * @param right The right side of the equality operator
		 *
		 * @return True if matrices are the same, false otherwise
		 */
		const bool operator==(const Matrix4<T> &right) const;

		/**
		 * @brief Multiplication operator for sf::Vector3<T>
		 *
		 * @param right The sf::Vector3<T> on the right side of the operator
		 *
		 * @return The result of the multiplication
		 */
		sf::Vector3<T> operator*(const sf::Vector3<T> &right) const;
		// Matrix4<T> operator+(const sf::Vector3<T> &right) const;
		// Matrix4<T> operator-(const sf::Vector3<T> &right) const;

		/**
		 * @brief Translation matrix operation
		 *
		 * @param translation The vector of translation
		 *
		 * @return Reference to itself after application of the translation.
		 * 
		 * Reference allows stacking operations one right after the other.
		 */
		Matrix4<T> &translate(const sf::Vector3<T> &translation);

		/**
		 * @brief Rotation in X axis matrix operation
		 *
		 * @param angle The angle of rotation
		 *
		 * @return Reference to itself after application of the rotation
		 * 
		 * Reference allows stacking operations one right after the other.
		 */
		Matrix4<T> &rotateX(const float &angle);

		/**
		 * @brief Rotation in Y axis matrix operation
		 *
		 * @param angle The angle of rotation
		 *
		 * @return Reference to itself after application of the rotation
		 * 
		 * Reference allows stacking operations one right after the other.
		 */
		Matrix4<T> &rotateY(const float &angle);

		/**
		 * @brief Rotation in Z axis matrix operation
		 *
		 * @param angle The angle of rotation
		 *
		 * @return Reference to itself after application of the rotation
		 * 
		 * Reference allows stacking operations one right after the other.
		 */
		Matrix4<T> &rotateZ(const float &angle);

		/**
		 * @brief Scaling matrix operation
		 *
		 * @param scale The scale in 3 dimensions (x, y, z)
		 * 
		 * Scale of value 1 keeps the original size.
		 *
		 * @return Reference to itself after application of scaling
		 * 
		 * Reference allows stacking operations one right after the other.
		 */
		Matrix4<T> &scale(const sf::Vector3<T> &scale);

		/**
		 * @brief Mirror matrix operation
		 *
		 * Give true as an argument if transformation should be mirrored in the selected axis.
		 *
		 * @param xAxis The X axis
		 * @param yAxis The Y axis
		 * @param zAxis The Z axis
		 *
		 * @return Reference to itself after application of mirroring
		 * 
		 * Reference allows stacking operations one right after the other.
		 */
		Matrix4<T> &mirror(const bool xAxis, const bool yAxis, const bool zAxis);

		/**
		 * @brief Conversion to sf::Vector3 representation of the position (or translation) in the matrix
		 *
		 * @return The position from the matrix
		 */
		const sf::Vector3<T> toPosition() const;
		// void print(const std::string &prefix) const;

	private:
		T m_matrix[4][4];
	};

	template <typename T>
	Matrix4<T>::Matrix4()
	{
		m_matrix[0][0] = 1;
		m_matrix[0][1] = 0;
		m_matrix[0][2] = 0;
		m_matrix[0][3] = 0;
		m_matrix[1][0] = 0;
		m_matrix[1][1] = 1;
		m_matrix[1][2] = 0;
		m_matrix[1][3] = 0;
		m_matrix[2][0] = 0;
		m_matrix[2][1] = 0;
		m_matrix[2][2] = 1;
		m_matrix[2][3] = 0;
		m_matrix[3][0] = 0;
		m_matrix[3][1] = 0;
		m_matrix[3][2] = 0;
		m_matrix[3][3] = 1;
	}

	template <typename T>
	Matrix4<T>::Matrix4(	T a00, T a01, T a02, T a03,
						T a10, T a11, T a12, T a13,
						T a20, T a21, T a22, T a23,
						T a30, T a31, T a32, T a33 )
	{
		m_matrix[0][0] = a00;
		m_matrix[0][1] = a01;
		m_matrix[0][2] = a02;
		m_matrix[0][3] = a03;
		m_matrix[1][0] = a10;
		m_matrix[1][1] = a11;
		m_matrix[1][2] = a12;
		m_matrix[1][3] = a13;
		m_matrix[2][0] = a20;
		m_matrix[2][1] = a21;
		m_matrix[2][2] = a22;
		m_matrix[2][3] = a23;
		m_matrix[3][0] = a30;
		m_matrix[3][1] = a31;
		m_matrix[3][2] = a32;
		m_matrix[3][3] = a33;
	}

	template <typename T>
	template <typename U>
	Matrix4<T>::Matrix4(const Matrix4<U> &matrix)
	{
		for(unsigned i = 0; i < 4; i++)
		{
			for(unsigned j = 0; j < 4; j++)
			{
				m_matrix[i][j] = static_cast<T>(matrix.m_matrix[i][j]);
			}
		}
	}

	template <typename T>
	T *Matrix4<T>::operator[](const unsigned &index)
	{
		return this->m_matrix[index];
	}

	template <typename T>
	const T *Matrix4<T>::operator[](const unsigned &index) const
	{
		return this->m_matrix[index];
	}

	template <typename T>
	Matrix4<T> Matrix4<T>::operator-() const
	{
		Matrix4<T> result;
	    const Matrix4<T> &m = *this;

	    result[0][0] = m[1][1]  * m[2][2] * m[3][3] - 
	             m[1][1]  * m[2][3] * m[3][2] - 
	             m[2][1]  * m[1][2]  * m[3][3] + 
	             m[2][1]  * m[1][3]  * m[3][2] +
	             m[3][1] * m[1][2]  * m[2][3] - 
	             m[3][1] * m[1][3]  * m[2][2];

	    result[1][0] = -m[1][0]  * m[2][2] * m[3][3] + 
	              m[1][0]  * m[2][3] * m[3][2] + 
	              m[2][0]  * m[1][2]  * m[3][3] - 
	              m[2][0]  * m[1][3]  * m[3][2] - 
	              m[3][0] * m[1][2]  * m[2][3] + 
	              m[3][0] * m[1][3]  * m[2][2];

	    result[2][0] = m[1][0]  * m[2][1] * m[3][3] - 
	             m[1][0]  * m[2][3] * m[3][1] - 
	             m[2][0]  * m[1][1] * m[3][3] + 
	             m[2][0]  * m[1][3] * m[3][1] + 
	             m[3][0] * m[1][1] * m[2][3] - 
	             m[3][0] * m[1][3] * m[2][1];

	    result[3][0] = -m[1][0]  * m[2][1] * m[3][2] + 
	               m[1][0]  * m[2][2] * m[3][1] +
	               m[2][0]  * m[1][1] * m[3][2] - 
	               m[2][0]  * m[1][2] * m[3][1] - 
	               m[3][0] * m[1][1] * m[2][2] + 
	               m[3][0] * m[1][2] * m[2][1];

	    result[0][1] = -m[0][1]  * m[2][2] * m[3][3] + 
	              m[0][1]  * m[2][3] * m[3][2] + 
	              m[2][1]  * m[0][2] * m[3][3] - 
	              m[2][1]  * m[0][3] * m[3][2] - 
	              m[3][1] * m[0][2] * m[2][3] + 
	              m[3][1] * m[0][3] * m[2][2];

	    result[1][1] = m[0][0]  * m[2][2] * m[3][3] - 
	             m[0][0]  * m[2][3] * m[3][2] - 
	             m[2][0]  * m[0][2] * m[3][3] + 
	             m[2][0]  * m[0][3] * m[3][2] + 
	             m[3][0] * m[0][2] * m[2][3] - 
	             m[3][0] * m[0][3] * m[2][2];

	    result[2][1] = -m[0][0]  * m[2][1] * m[3][3] + 
	              m[0][0]  * m[2][3] * m[3][1] + 
	              m[2][0]  * m[0][1] * m[3][3] - 
	              m[2][0]  * m[0][3] * m[3][1] - 
	              m[3][0] * m[0][1] * m[2][3] + 
	              m[3][0] * m[0][3] * m[2][1];

	    result[3][1] = m[0][0]  * m[2][1] * m[3][2] - 
	              m[0][0]  * m[2][2] * m[3][1] - 
	              m[2][0]  * m[0][1] * m[3][2] + 
	              m[2][0]  * m[0][2] * m[3][1] + 
	              m[3][0] * m[0][1] * m[2][2] - 
	              m[3][0] * m[0][2] * m[2][1];

	    result[0][2] = m[0][1]  * m[1][2] * m[3][3] - 
	             m[0][1]  * m[1][3] * m[3][2] - 
	             m[1][1]  * m[0][2] * m[3][3] + 
	             m[1][1]  * m[0][3] * m[3][2] + 
	             m[3][1] * m[0][2] * m[1][3] - 
	             m[3][1] * m[0][3] * m[1][2];

	    result[1][2] = -m[0][0]  * m[1][2] * m[3][3] + 
	              m[0][0]  * m[1][3] * m[3][2] + 
	              m[1][0]  * m[0][2] * m[3][3] - 
	              m[1][0]  * m[0][3] * m[3][2] - 
	              m[3][0] * m[0][2] * m[1][3] + 
	              m[3][0] * m[0][3] * m[1][2];

	    result[2][2] = m[0][0]  * m[1][1] * m[3][3] - 
	              m[0][0]  * m[1][3] * m[3][1] - 
	              m[1][0]  * m[0][1] * m[3][3] + 
	              m[1][0]  * m[0][3] * m[3][1] + 
	              m[3][0] * m[0][1] * m[1][3] - 
	              m[3][0] * m[0][3] * m[1][1];

	    result[3][2] = -m[0][0]  * m[1][1] * m[3][2] + 
	               m[0][0]  * m[1][2] * m[3][1] + 
	               m[1][0]  * m[0][1] * m[3][2] - 
	               m[1][0]  * m[0][2] * m[3][1] - 
	               m[3][0] * m[0][1] * m[1][2] + 
	               m[3][0] * m[0][2] * m[1][1];

	    result[0][3] = -m[0][1] * m[1][2] * m[2][3] + 
	              m[0][1] * m[1][3] * m[2][2] + 
	              m[1][1] * m[0][2] * m[2][3] - 
	              m[1][1] * m[0][3] * m[2][2] - 
	              m[2][1] * m[0][2] * m[1][3] + 
	              m[2][1] * m[0][3] * m[1][2];

	    result[1][3] = m[0][0] * m[1][2] * m[2][3] - 
	             m[0][0] * m[1][3] * m[2][2] - 
	             m[1][0] * m[0][2] * m[2][3] + 
	             m[1][0] * m[0][3] * m[2][2] + 
	             m[2][0] * m[0][2] * m[1][3] - 
	             m[2][0] * m[0][3] * m[1][2];

	    result[2][3] = -m[0][0] * m[1][1] * m[2][3] + 
	               m[0][0] * m[1][3] * m[2][1] + 
	               m[1][0] * m[0][1] * m[2][3] - 
	               m[1][0] * m[0][3] * m[2][1] - 
	               m[2][0] * m[0][1] * m[1][3] + 
	               m[2][0] * m[0][3] * m[1][1];

	    result[3][3] = m[0][0] * m[1][1] * m[2][2] - 
	              m[0][0] * m[1][2] * m[2][1] - 
	              m[1][0] * m[0][1] * m[2][2] + 
	              m[1][0] * m[0][2] * m[2][1] + 
	              m[2][0] * m[0][1] * m[1][2] - 
	              m[2][0] * m[0][2] * m[1][1];

		double det;
	    det = m[0][0] * result[0][0] + m[0][1] * result[1][0] + m[0][2] * result[2][0] + m[0][3] * result[3][0];

	    if(det == 0)
	    {
	        return Matrix4<T>();
	    }

	    det = 1.0 / det;

	    for(unsigned i = 0; i < 4; i++)
	    {
	    	for(unsigned j = 0; j < 4; j++)
	    	{
	    		result[i][j] *= det;
	    	}
	    }

	    return result;
	}

	template <typename T>
	Matrix4<T> Matrix4<T>::operator*(const Matrix4<T> &right) const
	{
		Matrix4<T> result;
		result[0][0] = (*this)[0][0]*right[0][0] + (*this)[0][1]*right[1][0] + (*this)[0][2]*right[2][0] + (*this)[0][3]*right[3][0];
		result[0][1] = (*this)[0][0]*right[0][1] + (*this)[0][1]*right[1][1] + (*this)[0][2]*right[2][1] + (*this)[0][3]*right[3][1];
		result[0][2] = (*this)[0][0]*right[0][2] + (*this)[0][1]*right[1][2] + (*this)[0][2]*right[2][2] + (*this)[0][3]*right[3][2];
		result[0][3] = (*this)[0][0]*right[0][3] + (*this)[0][1]*right[1][3] + (*this)[0][2]*right[2][3] + (*this)[0][3]*right[3][3];

		result[1][0] = (*this)[1][0]*right[0][0] + (*this)[1][1]*right[1][0] + (*this)[1][2]*right[2][0] + (*this)[1][3]*right[3][0];
		result[1][1] = (*this)[1][0]*right[0][1] + (*this)[1][1]*right[1][1] + (*this)[1][2]*right[2][1] + (*this)[1][3]*right[3][1];
		result[1][2] = (*this)[1][0]*right[0][2] + (*this)[1][1]*right[1][2] + (*this)[1][2]*right[2][2] + (*this)[1][3]*right[3][2];
		result[1][3] = (*this)[1][0]*right[0][3] + (*this)[1][1]*right[1][3] + (*this)[1][2]*right[2][3] + (*this)[1][3]*right[3][3];

		result[2][0] = (*this)[2][0]*right[0][0] + (*this)[2][1]*right[1][0] + (*this)[2][2]*right[2][0] + (*this)[2][3]*right[3][0];
		result[2][1] = (*this)[2][0]*right[0][1] + (*this)[2][1]*right[1][1] + (*this)[2][2]*right[2][1] + (*this)[2][3]*right[3][1];
		result[2][2] = (*this)[2][0]*right[0][2] + (*this)[2][1]*right[1][2] + (*this)[2][2]*right[2][2] + (*this)[2][3]*right[3][2];
		result[2][3] = (*this)[2][0]*right[0][3] + (*this)[2][1]*right[1][3] + (*this)[2][2]*right[2][3] + (*this)[2][3]*right[3][3];

		result[3][0] = (*this)[3][0]*right[0][0] + (*this)[3][1]*right[1][0] + (*this)[3][2]*right[2][0] + (*this)[3][3]*right[3][0];
		result[3][1] = (*this)[3][0]*right[0][1] + (*this)[3][1]*right[1][1] + (*this)[3][2]*right[2][1] + (*this)[3][3]*right[3][1];
		result[3][2] = (*this)[3][0]*right[0][2] + (*this)[3][1]*right[1][2] + (*this)[3][2]*right[2][2] + (*this)[3][3]*right[3][2];
		result[3][3] = (*this)[3][0]*right[0][3] + (*this)[3][1]*right[1][3] + (*this)[3][2]*right[2][3] + (*this)[3][3]*right[3][3];
		return result;
	}

	template <typename T>
	Matrix4<T> Matrix4<T>::operator+(const Matrix4<T> &right) const
	{
		Matrix4<T> result;
		for(unsigned i = 0; i < 4; i++)
		{
			for(unsigned j = 0; j < 4; j++)
			{
				result[i][j] = m_matrix[i][j] + right[i][j];
			}
		}
		return result;
	}

	template <typename T>
	Matrix4<T> Matrix4<T>::operator-(const Matrix4<T> &right) const
	{
		Matrix4<T> result;
		for(unsigned i = 0; i < 4; i++)
		{
			for(unsigned j = 0; j < 4; j++)
			{
				result[i][j] = m_matrix[i][j] - right[i][j];
			}
		}
		return result;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::operator*=(const Matrix4<T> &right)
	{
		(*this) = (*this) * right;
		return *this;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::operator+=(const Matrix4<T> &right)
	{
		*this = *this + right;
		return *this;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::operator-=(const Matrix4<T> &right)
	{
		*this = *this - right;
		return *this;
	}

	template <typename T>
	const bool Matrix4<T>::operator!=(const Matrix4<T> &right) const
	{
		for(unsigned i = 0; i < 4; i++)
		{
			for(unsigned j = 0; j < 4; j++)
			{
				if(m_matrix[i][j] != right[i][j])
					return true;
			}
		}
		return false;
	}

	template <typename T>
	const bool Matrix4<T>::operator==(const Matrix4<T> &right) const
	{
		for(unsigned i = 0; i < 4; i++)
		{
			for(unsigned j = 0; j < 4; j++)
			{
				if(m_matrix[i][j] != right[i][j])
					return false;
			}
		}
		return true;
	}

	template <typename T>
	sf::Vector3<T> Matrix4<T>::operator*(const sf::Vector3<T> &right) const
	{
		T arr[4] = {right.x, right.y, right.z, 1};
		T res[4] = {0};
		for(unsigned i = 0; i < 4; i++)
		{
			for(unsigned j = 0; j < 4; j++)
			{
				res[i] += m_matrix[i][j] * arr[j];
			}
		}
		sf::Vector3<T> result(res[0], res[1], res[2]);
		return result;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::translate(const sf::Vector3<T> &translation)
	{
		m_matrix[0][3] += translation.x;
		m_matrix[1][3] += translation.y;
		m_matrix[2][3] += translation.z;
		return *this;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::rotateX(const float &angle)
	{
		double emPI = 3.141592654;
		T rad = fmod(angle * emPI / 180.0, 2.0 * emPI);
		T cos_x = std::cos(rad);
		T sin_x = std::sin(rad);
		
		(*this) *= Matrix4<T>(	1, 0, 0, 0,
								0, cos_x, -sin_x, 0,
								0, sin_x, cos_x, 0,
								0, 0, 0, 1);
		return *this;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::rotateY(const float &angle)
	{
		double emPI = 3.141592654;
		T rad = fmod(angle * emPI / 180.0, 2.0 * emPI);
		T cos_y = std::cos(rad);
		T sin_y = std::sin(rad);
		
		(*this) *= Matrix4<T>(	cos_y, 0, sin_y, 0,
								0, 1, 0, 0,
								-sin_y, 0, cos_y, 0,
								0, 0, 0, 1);
		return *this;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::rotateZ(const float &angle)
	{
		double emPI = 3.141592654;
		T rad = fmod(angle * emPI / 180.0, 2.0 * emPI);
		T cos_z = std::cos(rad);
		T sin_z = std::sin(rad);
		
		(*this) *= Matrix4<T>(	cos_z, -sin_z, 0, 0,
								sin_z, cos_z, 0, 0,
								0, 0, 1, 0,
								0, 0, 0, 1);
		return *this;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::scale(const sf::Vector3<T> &scale)
	{
		(*this) *= Matrix4<T>(	scale.x, 0, 0, 0,
								0, scale.y, 0, 0, 
								0, 0, scale.z, 0,
								0, 0, 0, 1);
		return *this;
	}

	template <typename T>
	Matrix4<T> &Matrix4<T>::mirror(const bool xAxis, const bool yAxis, const bool zAxis)
	{
		Matrix4<T> mirrorMatrix;
		if(xAxis)
		{
			mirrorMatrix[0][0] = -1;
		}
		if(yAxis)
		{
			mirrorMatrix[1][1] = -1;
		}
		if(zAxis)
		{
			mirrorMatrix[2][2] = -1;
		}
		
		(*this) *= mirrorMatrix;
		return *this;
	}

	template <typename T>
	const sf::Vector3<T> Matrix4<T>::toPosition() const
	{
		return sf::Vector3<T>(m_matrix[0][3], m_matrix[1][3], m_matrix[2][3]);
	}

/*	template <typename T>
	void Matrix4<T>::print(const std::string &prefix) const
	{
		std::cout << prefix << std::endl;
		for(unsigned i = 0; i < 4; i++)
		{
			for(unsigned j = 0; j < 4; j++)
			{
				std::cout << m_matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}*/

	typedef Matrix4<float> Matrix4f;
	typedef Matrix4<int> Matrix4i;
	typedef Matrix4<unsigned> Matrix4u;
}//namespace em

