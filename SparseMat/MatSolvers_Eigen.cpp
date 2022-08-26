
#include "MatSolvers.hpp"
#include "SparseMatOperators.hpp"
#include <000_thirdparty/Eigen/IterativeLinearSolvers>
//#include <000_thirdparty/UnsupportedEigen/Eigen/IterativeSolvers>


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
bool MatSolvers::solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const SparseMat& matA, const Eigen::VectorXd& vecB, Eigen::VectorXd& results, bool init){
	/* �ݒ� */
	Eigen::ConjugateGradient<Eigen::SparseMatrix<double, Eigen::RowMajor>, Eigen::Lower|Eigen::Upper, Eigen::IncompleteCholesky<double, Eigen::Lower, Eigen::NaturalOrdering<int>>> iccg;
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
bool MatSolvers::solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const SparseMat& matA, const double* vecB, double* results, bool init){
	Eigen::VectorXd vecB2(size0);
	Eigen::VectorXd results2(size0);
	for(int i = 0 ; i < size0 ; i++){
		vecB2(i) = vecB[i];
	}
	bool bl = solveEigenICCG(size0, conv_cri, max_ite, matA, vecB2, results2, init);
	for(int i = 0 ; i < size0 ; i++){
		results[i] = results2(i);
	}
	return bl;
}

/*//=======================================================
// �� BiCGstab�ŉ���(Eigen�\���o)
//=======================================================*/
bool MatSolvers::solveEigenBiCGstab(const slv_int size0, const double conv_cri, const int max_ite, const SparseMat& matA, const Eigen::VectorXd& vecB, Eigen::VectorXd& results, bool init){
	/* �ݒ� */
	Eigen::BiCGSTAB<Eigen::SparseMatrix<double, Eigen::RowMajor>, Eigen::IncompleteLUT<double>> bicg;
	bicg.setMaxIterations(max_ite);
	bicg.setTolerance(conv_cri);

	bicg.compute(matA.matrix->matrix);
	if(init){
		results = bicg.solve(vecB);
	}else{
		results = bicg.solveWithGuess(vecB, results);
	}
	double err = bicg.error();
	//std::cout << "err " << err << std::endl;
	return(err <= conv_cri);
}
bool MatSolvers::solveEigenBiCGstab(const slv_int size0, const double conv_cri, const int max_ite, const SparseMat& matA, const double* vecB, double* results, bool init){
	Eigen::VectorXd vecB2(size0);
	Eigen::VectorXd results2(size0);
	for(int i = 0 ; i < size0 ; i++){
		vecB2(i) = vecB[i];
	}
	bool bl = solveEigenBiCGstab(size0, conv_cri, max_ite, matA, vecB2, results2, init);
	for(int i = 0 ; i < size0 ; i++){
		results[i] = results2(i);
	}
	return bl;
}


/*//=======================================================
// �� ICCG�ŉ���(Eigen�\���o)
//=======================================================*/
bool MatSolvers::solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const SparseMatC& matA, const Eigen::VectorXcd& vecB, Eigen::VectorXcd& results, bool init){
	/* �ݒ� */
	Eigen::ConjugateGradient<Eigen::SparseMatrix<dcomplex, Eigen::RowMajor>, Eigen::Lower|Eigen::Upper, Eigen::IncompleteCholesky<dcomplex, Eigen::Lower, Eigen::NaturalOrdering<int>>> iccg;
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
bool MatSolvers::solveEigenICCG(const slv_int size0, const double conv_cri, const int max_ite, const SparseMatC& matA, const dcomplex* vecB, dcomplex* results, bool init){
	Eigen::VectorXcd vecB2(size0);
	Eigen::VectorXcd results2(size0);
	for(int i = 0 ; i < size0 ; i++){
		vecB2(i) = vecB[i];
	}
	bool bl = solveEigenICCG(size0, conv_cri, max_ite, matA, vecB2, results2, init);
	for(int i = 0 ; i < size0 ; i++){
		results[i] = results2(i);
	}
	return bl;
}


/*//=======================================================
// �� BiCGstab�ŉ���(Eigen�\���o)
//=======================================================*/
bool MatSolvers::solveEigenBiCGstab(const slv_int size0, const double conv_cri, const int max_ite, const SparseMatC& matA, const Eigen::VectorXcd& vecB, Eigen::VectorXcd& results, bool init){
	/* �ݒ� */
	Eigen::BiCGSTAB<Eigen::SparseMatrix<dcomplex, Eigen::RowMajor>, Eigen::IncompleteLUT<dcomplex>> bicg;
	bicg.setMaxIterations(max_ite);
	bicg.setTolerance(conv_cri);

	bicg.compute(matA.matrix->matrix);
	if(init){
		results = bicg.solve(vecB);
	}else{
		results = bicg.solveWithGuess(vecB, results);
	}
	double err = bicg.error();
	//std::cout << "err " << err << std::endl;
	return(err <= conv_cri);
}
bool MatSolvers::solveEigenBiCGstab(const slv_int size0, const double conv_cri, const int max_ite, const SparseMatC& matA, const dcomplex* vecB, dcomplex* results, bool init){
	Eigen::VectorXcd vecB2(size0);
	Eigen::VectorXcd results2(size0);
	for(int i = 0 ; i < size0 ; i++){
		vecB2(i) = vecB[i];
	}
	bool bl = solveEigenBiCGstab(size0, conv_cri, max_ite, matA, vecB2, results2, init);
	for(int i = 0 ; i < size0 ; i++){
		results[i] = results2(i);
	}
	return bl;
}


/* end of namespace */
};


