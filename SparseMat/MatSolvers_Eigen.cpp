
#include "MatSolvers.hpp"
#include "SparseMatOperators.hpp"
#include <000_thirdparty/Eigen/IterativeLinearSolvers>
#include <000_thirdparty/UnsupportedEigen/Eigen/IterativeSolvers>


/* ��p���O��� */
namespace SRLfem{


/*

//=======================================================
//=======================================================
//=======================================================
Eigen�\���o
//=======================================================
//=======================================================

*/
	
	
/*//=======================================================
// �� ICCG�ŉ���(Eigen�\���o)
//=======================================================*/
bool MatSolvers::solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const double accera, const SparseMat& matA, const Eigen::VectorXd& vecB, Eigen::VectorXd& results, bool init){
	/* �ݒ� */
	Eigen::ConjugateGradient<Eigen::SparseMatrix<double>, Eigen::Lower|Eigen::Upper, Eigen::IncompleteCholesky<double>> iccg;
	iccg.setMaxIterations(max_ite);
	iccg.setTolerance(conv_cri);

	iccg.compute(matA.matrix->matrix);
	if(init){
		results = iccg.solve(vecB);
	}else{
		results = iccg.solveWithGuess(vecB, results);
	}
	double err = iccg.error();
	//std::cout << "err " << err << std::endl;
	return(err <= conv_cri);
}



/* end of namespace */
};


