#ifndef _CONFIG_H_
#define _CONFIG_H_

// --------------------
// �R���p�C�����ݒ�
// --------------------

// --- �^�[�Q�b�gCPU�̑I��

#if !defined(USE_MAKEFILE)

// USE_AVX512 : AVX-512(�T�[�o�[����Skylake�ȍ~)�ŃT�|�[�g���ꂽ���߂��g�����B
// USE_AVX2   : AVX2(Haswell�ȍ~)�ŃT�|�[�g���ꂽ���߂��g�����Bpext�ȂǁB
// USE_SSE42  : SSE4.2�ŃT�|�[�g���ꂽ���߂��g�����Bpopcnt���߂ȂǁB
// USE_SSE41  : SSE4.1�ŃT�|�[�g���ꂽ���߂��g�����B_mm_testz_si128�ȂǁB
// USE_SSE2   : SSE2  �ŃT�|�[�g���ꂽ���߂��g�����B
// NO_SSE     : SSE�͎g�p���Ȃ��B
// (Windows��64bit�����Ǝ����I��SSE2�͎g����͂�)
// noSSE �� SSE2 �� SSE4.1 �� SSE4.2 �� AVX2 ��  AVX-512

// Visual Studio�̃v���W�F�N�g�ݒ�Łu�\���̃v���p�e�B�v���uC / C++�v���u�R�[�h�����v���u�g�����߃Z�b�g��L���ɂ���v
// �̂Ƃ���̐ݒ�̕ύX���Y�ꂸ�ɁB

// �^�[�Q�b�gCPU�̂Ƃ��낾��define���Ă��������B(�c��͎����I��define����܂��B)

//#define USE_AVX512
#define USE_AVX2
//#define USE_SSE42
//#define USE_SSE41
//#define USE_SSE2
//#define NO_SSE

#else

// Makefile���g����build����Ƃ��́A
// $ make avx2
// �̂悤�ɂ��ăr���h����Ύ����I��AVX2�p���r���h����܂��B

#endif


// �ʗ�hash key��64bit�����A�����128�ɂ����Position::state()->long_key()����128bit hash key��
// ������悤�ɂȂ�B�������ɋǖʂ������ɍ��v���Ă��邩�ǂ����𔻒肵�����Ƃ��Ȃǂɗp����B
// �����p�̋@�\�Ȃ̂ŁA128bit,256bit��hash key�̃T�|�[�g��AVX2�̂݁B
#define HASH_KEY_BITS 64
//#define HASH_KEY_BITS 128
//#define HASH_KEY_BITS 256


// �ʏ�T�����̍ő�T���[��
#define MAX_PLY_NUM 127

// --- �f�o�b�O���̕W���o�͂ւ̋ǖʕ\���Ȃǂɓ��{�ꕶ�����p����B

#define PRETTY_JP

//
// �ȉ��A�f�t�H���g�ł�define���Ă��Ȃ��̂ŁA�K�v�ɉ�����define���邱�ƁB
//

// --- assert�̃��x����6�i�K�ŁB
//  ASSERT_LV 0 : assert�Ȃ�(�S�̓I�ȏ���������)
//  ASSERT_LV 1 : �y�ʂ�assert
//  �@�@�@�c
//  ASSERT_LV 5 : �d�x��assert(�S�̓I�ȏ������x��)
// ���܂�d�x��assert�ɂ���ƁA�T�����\��������̂Ŏ��ԓ�����ɒ��ׂ���ǖʐ����ቺ���邩��
// ���̂ւ�̃o�����X�����[�U�[�����߂��悤�ɂ��̎d�g�݂𓱓��B

//#define ASSERT_LV 3

// --- ASSERT�̃��_�C���N�g
// ASSERT�Ɉ������������Ƃ��ɁA�����"Error : x=1"�̂悤�ɕW���o�͂ɏo�͂���B

//#define USE_DEBUG_ASSERT


// --- USI�g���R�}���h��"test"�R�}���h��L���ɂ���B
// ���ɂ�������̃e�X�g�R�[�h��������Ă���̂ŃR�[�h�T�C�Y���c��ނ��߁A
// �v�l�G���W���Ƃ��ă����[�X����Ƃ��̓R�����g�A�E�g�����ق��������Ǝv���B

//#define ENABLE_TEST_CMD

// --- StateInfo�ɒ��O�̎w����A�ړ���������Ȃǂ̏���ۑ����Ă����̂�
// ���ꂪ�ۑ�����Ă���Ƌl�������[�`���Ȃǂ����삷��ꍇ�ɂ����Ă����܂ł̎菇��\������̂��ȒP�ɂȂ�B
// (Position::moves_from_start_pretty()�Ȃǂɂ��A�킩��₷���菇��������B
// �������ʏ�T���ɂ����Ă͂��x���Ȃ�̂Ŏv�l�G���W���Ƃ��ă����[�X����Ƃ��ɂ͖����ɂ��Ă������ƁB

//#define KEEP_LAST_MOVE

// ���͋l�ߗp�v�l�G���W���Ȃǂŕ]���֐����g��Ȃ��Ƃ��ɂ܂ŕ]���֐��p�̃e�[�u����
// �m�ۂ���̂͂��������Ȃ��̂ŁA���̃e�[�u�����m�ۂ��邩�ǂ�����I�����邽�߂̃I�v�V�����B
// �]���֐���p����Ȃ�A�ǂꂩ���I�����ׂ��B

// �u���v�����Ă������..�����ς�
// �u���v�����Ă������..�Q�l�����B
// �u�~�v�����Ă������..�����\��Ȃ�
// �u�H�v�����Ă������..�������邩��
// �u�I�v�����Ă������..���Ď������Ă������T�|�[�g���I���������́B

// #define EVAL_NO_USE    // �I�@�]���֐��Ȃ��B��4
// #define EVAL_MATERIAL  // ��  ��݂̂̕]���֐�
// #define EVAL_PP        // �~  �c�c�J�i�^ 2��֌W(�J���\��Ȃ�)
// #define EVAL_KPP       // �I  Bonanza�^ 3��֌W�A��ԂȂ�
// #define EVAL_KPPT      // ��  Bonanza�^ 3��֌W�A��Ԃ�(Apery WCSC26����)
// #define EVAL_KPP_KKPT  // ��  KK��Ԃ��� + KKP��Ԃ��� + KPP��ԂȂ�(Ponanza WCSC26�����H)
// #define EVAL_KPP_KKPT_FV_VAR // �� KPP_KKPT�Ɠ���B��5
// #define EVAL_KPP_PPT   // �~  PP��Ԃ��� + KKP��Ԃ��� + KPP��ԂȂ�(�����A�r���܂�)��1
// #define EVAL_KPPP_KKPT // ��  KKP��Ԃ��� + KPP��ԂȂ� + KPPP(4��֌W)��ԂȂ��B���@��2,��3
// #define EVAL_KPPPT     // ��  KPPP(4��֌W)��Ԃ���B���@�����������ǂ��܂ЂƂ������̂ō����v�Z���������B��2,��3
// #define EVAL_PPET      // �~  �Z�I�^ 2��+����+���(�����\��Ȃ�)
// #define EVAL_KKPPT     // ��  KKPP�^ 4��֌W ��Ԃ���B(55�����A56�����ł��g������)��3
// #define EVAL_KKPP_KKPT // ��  KKPP�^ 4��֌W ��Ԃ�KK,KKPT�ɂ݂̂���B��3
// #define EVAL_NABLA     // ��  ��(�i�u��) �]���֐�(����A����J)
// #define EVAL_HELICES   // �H  �����]���֐�

// ��1 : KPP_PPT�́A�����v�Z���ʓ|�Ŋ��ɍ���Ȃ����Ƃ����������̂ł�����g�����炢�Ȃ�KPP_KKPT�ŏ\�����Ƃ������_�B
// ��2 : �����������ǂ��܂ЂƂ������̂ō����v�Z���������B���̂��ߒx�����āA�����g�����ɂȂ�Ȃ��B�\�[�X�R�[�h�̎Q�l�p�B
// ��3 : ���̃V���{���̒l�Ƃ��đΏۂƂ��鉤�̏��̐����w�肷��B�Ⴆ��EVAL_KPPPT��27��define����Ƌʂ����w(3*9�� = 27)��
//       ����Ƃ��݂̂�KPPPT�̕]���ΏۂƂȂ�B(�����ȊO�ɋʂ�����Ƃ��͕��ʂ�KPPT)
// ��4 : �ȑO�AEVAL_NO_USE�Ƃ����]���֐��Ȃ��̂��̂��I���ł���悤�ɂȂ��Ă������A
//       ���v���قƂ�ǂȂ���ɁA�\�[�X�R�[�h��ifdef�̗��ɂȂ�̂œǂ݂Â炢�̂Ńo�b�T���폜�����B
//		�����EVAL_MATERIAL���g���Ɨǂ��B�ǉ��R�X�g�͂قږ����ł���B
// ��5 : �ϒ�EvalList��p���郊�t�@�����X�����BKPP_KKPT�^�ɔ�ׂĂ킸���ɒx�����A�g���������ɍ����A
//      �ɂ߂Ĕ����������Ȃ̂ŁA����A�]���֐��̊g���́A������x�[�X�ɂ���Ă������ƂɂȂ�Ǝv���B


// �]���֐������t�ǖʂ���w�K������Ƃ��Ɏg���Ƃ��̃��[�h
// #define EVAL_LEARN

// Eval::compute_eval()��Learner::add_grad()���Ăяo���O��EvalList�̑g�݊������s�Ȃ��@�\��񋟂���B
// �]���֐��̎����ɗp����B�ڂ����́AEval::make_list_function�ɏ����Ă�������Ȃǂ�ǂނ��ƁB
// #define USE_EVAL_MAKE_LIST_FUNCTION

// ���̋@�\�́A��˂��牤�̕]���֐��̊J��/�����p�̋@�\�ŁA���܂̂Ƃ����ʃ��[�U�[�ɂ͒񋟂��Ă��Ȃ��B
// �]���֐��ԍ����w�肷��Ƃ��̕]���֐��������A���̕]���֐��t�@�C���̓ǂݍ���/�����o���Ɏ����I�ɑΉ����āA
// ���]���֐��̋��`������̕ϊ���"test convert"�R�}���h�Ŏ����I�ɏo����悤�ɂȂ�Ƃ����A��肩�������@�\
// #define EVAL_EXPERIMENTAL 0001

// ��������(������̗���)�̃��C�u������p���邩�B
// ������1��l�ߔ���Ȃǂł͂��̃��C�u�������K�v�B
// do_move()�̂Ƃ��ɗ����̍����X�V���s�Ȃ��̂ŁAdo_move()�͏����x���Ȃ�B(���̑���A�������g����悤�ɂȂ�)
//#define LONG_EFFECT_LIBRARY

// 1��l�ߔ��胋�[�`����p���邩�B
// LONG_EFFECT_LIBRARY���L���ȂƂ��́A�����𗘗p���������Ȉ��l�߁B
// LONG_EFFECT_LIBRARY�������ȂƂ��́ABonanza6���̈��l�߁B
//#define USE_MATE_1PLY

// Position::see()��p���邩�B�����SEE(Static Exchange Evaluation : �ÓI��荇���]��)�̒l��Ԃ��֐��B
// #define USE_SEE

// PV(�ǂ݋�)��\������Ƃ��ɒu���\�̎w����������W�߂Ă��ĕ\�����邩�B
// ���O��PV���Ǘ�����RootMoves::pv���X�V����Ȃ�A���̋@�\���g���K�v�͂Ȃ��B
// �����PV�̍X�V���s�v�Ȃ̂Ŏ������ȒP�����APonder�̎w�����Ԃ����߂ɂ�
// PV����ɐ���ɍX�V����Ă��Ȃ��Ƃ����Ȃ��̂ōŋ߂͂��̕��@�͍D�܂�Ȃ��B
// ������ShogiGUI�̉�̓��[�h�ł͎v�l�G���W�����o�͂����Ō�̓ǂ݋؂��L�^����悤�Ȃ̂ŁA
// �v�l��r���őł��؂�Ƃ��ɁAfail low/fail high���N���Ă���ƁA���r���[��PV���o�͂���A���ꂪ�����Ɏc��B
// ���ƌ����āA���̂Ƃ���PV�̏o�͂����Ȃ��ƁA�Ō�ɏo�͂��ꂽPV��best move�Ƃ͈قȂ�\��������̂ŁA
// ����͂�낵���Ȃ��B�������[�h�p�̎v�l�I�v�V������p�ӂ��ׂ��B
// #define USE_TT_PV

// ��Ղ����R�}���h("makebook")��L���ɂ���B
// #define ENABLE_MAKEBOOK_CMD

// ���ʎ��̐錾������p���邩
// #define USE_ENTERING_KING_WIN

// TimeMangement�N���X�ɁA����̎v�l���Ԃ��v�Z����@�\��ǉ����邩�B
// #define USE_TIME_MANAGEMENT

// �u���\�̂Ȃ���eval�������Ȃ�
// #define NO_EVAL_IN_TT

// ONE_PLY == 1�ɂ��邽�߂̃��[�h�B������w�肵�Ă��Ȃ����ONE_PLY == 2
// #define ONE_PLY_EQ_1

// �I�[�_�����O�Ɏg���Ă���Stats�̔z��̂Ȃ��ŋ�ł��̂��߂�bit�����B
// #define USE_DROPBIT_IN_STATS

// �w���萶���̂Ƃ��ɏ��16bit��to(�ړ���̏�)�ɗ������i�[����B
// #define KEEP_PIECE_IN_GENERATE_MOVES

// �]���֐����v�Z�����Ƃ��ɁA�����HashTable�ɋL�����Ă����@�\�BKPPT�]���֐��ɂ����Ă̂݃T�|�[�g�B
// #define USE_EVAL_HASH

// sfen��256bit��pack����@�\�Aunpack����@�\��L���ɂ���B
// �����define�����Position::packe_sfen(),unpack_sfen()���g����悤�ɂȂ�B
// #define USE_SFEN_PACKER

// �u���\��probe�ɕK�����s����ݒ�
// ���Ȑ�����������̊w�K��qsearch()��PV���~�����Ƃ���
// �u���\��hit���Ď}���肳�ꂽ�Ƃ���PV�������Ȃ��̉������̂�
// #define USE_FALSE_PROBE_IN_TT

// �]���֐��p�����[�^�[�����L��������p���đ��v���Z�X�̂��̂Ƌ��L����B
// ���Ȃ��������̃}�V���Ŏv�l�G���W�������\�������グ�悤�Ƃ����Ƃ��Ƀ������s���ɂȂ�̂�
// �]���֐���shared memory��p���đ��̃v���Z�X�Ƌ��L����@�\�B(�Ή����Ă���̂͂��܂̂Ƃ���KPPT�]���֐��̂݁B����Windows����)
// #define USE_SHARED_MEMORY_IN_EVAL

// USI�v���g�R����gameover�R�}���h�������Ă����Ƃ��� gameover_handler()���Ăяo���B
// #define USE_GAMEOVER_HANDLER

// EVAL_HASH�Ŏg�p���郁�����Ƃ��đ傫�ȃ��������m�ۂ��邩�B
// �����ON����Ɛ�%�������������ɁA�������g�p�ʂ�1GB�قǑ�����B
// #define USE_LARGE_EVAL_HASH

// GlobalOption�Ƃ����AEVAL_HASH��L��/������؂�ւ�����A�u���\�̗L��/������؂�ւ����肷��
// �I�v�V�����̂��߂̕ϐ����g����悤�ɂȂ�B�X�s�[�h��1%���炢�x���Ȃ�̂ő��p�̃r���h�ł̓I�t�𐄏��B
// #define USE_GLOBAL_OPTIONS

// �g�[�i�����g(���)�p�̃r���h�B�ŐVCPU(���܂�AVX2)�p��EVAL_HASH�傫�߁BEVAL_LEARN�ATEST_CMD�g�p�s�BASSERT�Ȃ��BGlobalOptions�Ȃ��B
// #define FOR_TOURNAMENT

// �����̕ϊ��Ȃǂ��s�Ȃ��c�[���Z�b�g�BCSA,KIF,KIF2(KI2)�`���Ȃǂ̓��o�͂�S���B
// �����define����ƁAextra/kif_converter/ �t�H���_�ɂ��������w����\���̕ϊ����s�Ȃ��֐��Q���g�p�ł���悤�ɂȂ�B
// #define USE_KIF_CONVERT_TOOLS

// 128GB�����̒u���\���g�������Ƃ��p�B
// ���̃V���{�����`�����Options["Hash"]�Ƃ���131072(=128*1024[MB]�B���Ȃ킿128GB)�����̒u���\��������悤�ɂȂ�B
// Stockfish�̃R�~���j�e�B�ł͂܂��c�_���Ȃ̂Ńf�t�H���g�ŃI�t�ɂ��Ă����B
// cf. 128 GB TT size limitation : https://github.com/official-stockfish/Stockfish/issues/1349
// #define USE_HUGE_HASH

// --------------------
// release configurations
// --------------------

// --- �ʏ�̎v�l�G���W���Ƃ��Ď��s�t�@�C�������J����Ƃ��p�̐ݒ�W

// ��˂��牤2018 with ���������{
#if defined(YANEURAOU_2018_OTAFUKU_ENGINE)
#define ENGINE_NAME "YaneuraOu 2018 Otafuku (dolphin)"
#define EVAL_KPPT
//#define EVAL_KPP_KKPT

#define USE_EVAL_HASH
#define USE_SEE
#define USE_MATE_1PLY
#define USE_ENTERING_KING_WIN
#define USE_TIME_MANAGEMENT
#define KEEP_PIECE_IN_GENERATE_MOVES
#define ONE_PLY_EQ_1

// �f�o�b�O����
//#define ASSERT_LV 3
//#define USE_DEBUG_ASSERT

#define ENABLE_TEST_CMD
// �w�K���݂̃I�v�V����
#define USE_SFEN_PACKER
// �w�K�@�\��L���ɂ���I�v�V�����B
#define EVAL_LEARN

// ��Ր�������
#define ENABLE_MAKEBOOK_CMD
// �]���֐������p���ĕ����v���Z�X�����グ���Ƃ��̃�������ߖ�B(���܂̂Ƃ���Windows����)
#define USE_SHARED_MEMORY_IN_EVAL
// �p�����[�^�[�̎�����������
#define USE_GAMEOVER_HANDLER
//#define LONG_EFFECT_LIBRARY

// GlobalOptions�͗L���ɂ��Ă����B
#define USE_GLOBAL_OPTIONS
#endif



// �ɂ�˂��牤2018(����J)
#if defined(YANEURAOU_2018_GOKU_ENGINE)
#define ENGINE_NAME "YaneuraOu 2018 GOKU"

//#define EVAL_KPPT
#define EVAL_KPP_KKPT

//#define USE_HELICES_MIRROR
//#define EVAL_HELICES 81

//#define USE_KPPP_KKPT_MIRROR
//#define EVAL_KPPP_KKPT 18
//#define EVAL_KPPP_KKPT 36

//#define USE_KPPPT_MIRROR
//#define EVAL_KPPPT 27
//#define EVAL_KPPPT 18

//#define EVAL_KKPP_KKPT 36
//#define EVAL_KKPP_KKPT 45
//#define EVAL_KKPPT 36

//#define EVAL_KPP_KKPT_FV_VAR

//#define EVAL_NABLA

//#define EVAL_MATERIAL

// �������̕]���֐�
// �]���֐��̔ԍ���I���ł���B0001�`9999����I�ԁB
// �ԍ��Ƃ��āA0000�́Aif EVAL_EXPERIMENTAL == 0000�Ɣ��肵�悤�Ƃ����Ƃ��ɁAC++�̌���d�l�Ƃ���
// �V���{������`����Ă��Ȃ��Ƃ����̏��������^���Ɣ��肳��Ă��܂��̂Ŏg���Ȃ��B
//#define EVAL_EXPERIMENTAL 0005

#define USE_EVAL_HASH
#define USE_SEE
#define USE_MATE_1PLY
#define USE_ENTERING_KING_WIN
#define USE_TIME_MANAGEMENT
#define KEEP_PIECE_IN_GENERATE_MOVES
#define ONE_PLY_EQ_1

// �f�o�b�O����
//#define ASSERT_LV 3
//#define USE_DEBUG_ASSERT

#define ENABLE_TEST_CMD
// �w�K���݂̃I�v�V����
#define USE_SFEN_PACKER
// �w�K�@�\��L���ɂ���I�v�V�����B
#define EVAL_LEARN
// �J�����̋��t�ǖʂ̐����R�}���h
#define USE_GENSFEN2018

// ��Ր�������
#define ENABLE_MAKEBOOK_CMD
// �]���֐������p���ĕ����v���Z�X�����グ���Ƃ��̃�������ߖ�B(���܂̂Ƃ���Windows����)
#define USE_SHARED_MEMORY_IN_EVAL
// �p�����[�^�[�̎�����������
#define USE_GAMEOVER_HANDLER
//#define LONG_EFFECT_LIBRARY

// GlobalOptions�͗L���ɂ��Ă����B
#define USE_GLOBAL_OPTIONS
#endif


#if defined(YANEURAOU_2018_TNK_ENGINE)
#define ENGINE_NAME "FF2"
#define EVAL_NNUE

#define USE_EVAL_HASH
#define USE_SEE
#define USE_MATE_1PLY
#define USE_ENTERING_KING_WIN
#define USE_TIME_MANAGEMENT
#define KEEP_PIECE_IN_GENERATE_MOVES
#define ONE_PLY_EQ_1

// �f�o�b�O����
//#define ASSERT_LV 3
//#define USE_DEBUG_ASSERT

#define ENABLE_TEST_CMD
// �w�K���݂̃I�v�V����
#define USE_SFEN_PACKER
// �w�K�@�\��L���ɂ���I�v�V�����B
#define EVAL_LEARN

// ��Ր�������
#define ENABLE_MAKEBOOK_CMD
// �]���֐������p���ĕ����v���Z�X�����グ���Ƃ��̃�������ߖ�B(���܂̂Ƃ���Windows����)
//#define USE_SHARED_MEMORY_IN_EVAL
// �p�����[�^�[�̎�����������
#define USE_GAMEOVER_HANDLER
//#define LONG_EFFECT_LIBRARY

// GlobalOptions�͗L���ɂ��Ă����B
#define USE_GLOBAL_OPTIONS

// �T������YANEURAOU_2018_OTAFUKU_ENGINE���g���B
#define YANEURAOU_2018_OTAFUKU_ENGINE
#endif


#ifdef LOCAL_GAME_SERVER
#define ENGINE_NAME "YaneuraOu Local Game Server"
#define EVAL_MATERIAL
#define ASSERT_LV 3 // ���[�J���Q�[���T�[�o�[�Ahost���̑��x�͂���قǗv������Ȃ��̂�ASSERT_LV��3�ɂ��Ă����B
#define KEEP_LAST_MOVE
#define USE_ENTERING_KING_WIN
#endif


// --- ���͋l�߃G���W���Ƃ��Ď��s�t�@�C�������J����Ƃ��p�̐ݒ�W

#ifdef HELP_MATE_ENGINE
#define ENGINE_NAME "YaneuraOu help mate solver"
#define KEEP_LAST_MOVE
#undef  MAX_PLY_NUM
#define MAX_PLY_NUM 65000
#undef HASH_KEY_BITS
#define HASH_KEY_BITS 128
#define EVAL_MATERIAL
#endif

// --- �l�����G���W���Ƃ��Ď��s�t�@�C�������J����Ƃ��p�̐ݒ�W

#ifdef MATE_ENGINE
#define ENGINE_NAME "YaneuraOu mate solver"
#define KEEP_LAST_MOVE
#undef  MAX_PLY_NUM
#define MAX_PLY_NUM 2000
#define USE_SEE
#define USE_MATE_1PLY
#define EVAL_MATERIAL
#define LONG_EFFECT_LIBRARY
#define USE_KEY_AFTER
#define ENABLE_TEST_CMD
#endif

// --- ���[�U�[�̎���G���W���Ƃ��Ď��s�t�@�C�������J����Ƃ��p�̐ݒ�W

#ifdef USER_ENGINE
#define ENGINE_NAME "YaneuraOu user engine"
#define EVAL_KPP
#endif

// --------------------
//   for tournament
// --------------------

// �g�[�i�����g(���)�p�ɁA�΋ǂɕs�v�Ȃ��̂����ׂč킬���Ƃ��B
#if defined(FOR_TOURNAMENT)
#undef ASSERT_LV
#undef EVAL_LEARN
#undef ENABLE_TEST_CMD
#define USE_LARGE_EVAL_HASH
#undef USE_GLOBAL_OPTIONS
#endif

// --------------------
//   for learner
// --------------------

// �w�K���ɂ�EVAL_HASH�𖳌������Ă����Ȃ��ƁArmse�̌v�Z�̂Ƃ��Ȃǂ�eval hash��hit���Ă��܂��A
// �������v�Z�ł��Ȃ��B���̂��߁AEVAL_HASH�𓮓I�ɖ��������邽�߂̃I�v�V������p�ӂ���B
#if defined(EVAL_LEARN)
#define USE_GLOBAL_OPTIONS
#endif

// �]���֐��̎����p�̂Ƃ��́AEvalList�̑g�݊������K�v�ɂȂ�B
#if EVAL_EXPERIMENTAL >= 0001
#define USE_EVAL_MAKE_LIST_FUNCTION
#endif

// --------------------
//   GlobalOptions
// --------------------

#if defined(USE_GLOBAL_OPTIONS)

struct GlobalOptions_
{
	// eval hash��L��/����������B
	// (USE_EVAL_HASH��define����Ă��Ȃ��ƗL���ɂ͂Ȃ�Ȃ��B)
	bool use_eval_hash;

	// �u���\��probe()��L����/����������B
	// (�����������TT.probe()���K��miss hit����悤�ɂȂ�)
	bool use_hash_probe;

	// �X���b�h���Ƃɒu���\��p�ӂ���ݒ�
	// Learner::search(),Leaner::qsearch()���ĂԂƂ��ɃX���b�h���Ƃɒu���\���p�ӂ���Ă��Ȃ��ƌ��Ȃ炱����Ăяo���B
	// ���̋@�\��L���ɂ����ꍇ�ATT.new_search()���Ăяo�����Ƃ���Options["Threads"]�̒l�ɏ]���āA
	// �u���\�𕪊�����̂�Learner::search()���ĂԂ܂łɎ��O��TT.new_search()���Ăяo�����ƁB
	bool use_per_thread_tt;

	// �u���\��TTEntry�̐��オ�قȂ�Ȃ�A�l(TTEntry.value)�͐M�p�ł��Ȃ��Ɖ��肷��t���O�B
	// TT.probe()�̂Ƃ��ɁATTEntry��TT.generation�Ƃ������Ɉ�v���Ȃ��ꍇ�́A
	// �u���\��hit���Ă��A����TTEntry��VALUE_NONE��Ԃ��B
	// �������邱�ƂŁAhash�Փ˂��Ă������Ȓl���������܂�Ă��Ă����������ł���B
	// gensfen�R�}���h�ł��̋@�\���K�v�������B
	// cf. http://yaneuraou.yaneu.com/2017/06/30/%E3%80%90%E8%A7%A3%E6%B1%BA%E3%80%91gensfen%E3%81%A7%E6%95%99%E5%B8%AB%E5%B1%80%E9%9D%A2%E7%94%9F%E6%88%90%E6%99%82%E3%81%AB%E9%81%85%E3%81%8F%E3%81%AA%E3%82%8B%E5%95%8F%E9%A1%8C/
	bool use_strict_generational_tt;

	GlobalOptions_()
	{
		use_eval_hash = use_hash_probe = true;
		use_per_thread_tt = use_strict_generational_tt = false;
	}
};

extern GlobalOptions_ GlobalOptions;

#endif

// --------------------
//      include
// --------------------

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
#include <stack>
#include <memory>
#include <map>
#include <iostream>
#include <fstream>
#include <mutex>
#include <thread>		// ���̂���Mutex��typedef����̂�
#include <condition_variable>
#include <cstring>		// std::memcpy()
#include <cmath>		// log(),std::round()
#include <climits>		// INT_MAX
#include <cstddef>		// offsetof
#include <array>
#include <functional>	// function 
#include <limits>       // numeric_limits

// --------------------
//      configure
// --------------------

// --- assertion tools

// DEBUG�r���h�łȂ���assert������������Ă��܂��̂Ŗ���������Ȃ�ASSERT
// �̈ӂɃ������A�N�Z�X�ᔽ���N�����R�[�h�B
// USE_DEBUG_ASSERT���L���ȂƂ��ɂ́AASSERT�̓��e���o�͂������ƁA3�b�҂��Ă���
// �A�N�Z�X�ᔽ�ɂȂ�悤�ȃR�[�h�����s����B
#if !defined (USE_DEBUG_ASSERT)
#define ASSERT(X) { if (!(X)) *(int*)1 = 0; }
#else
#define ASSERT(X) { if (!(X)) { std::cout << "\nError : ASSERT(" << #X << "), " << __FILE__ << "(" << __LINE__ << "): " << __func__ << std::endl; \
 std::this_thread::sleep_for(std::chrono::microseconds(3000)); *(int*)1 =0;} }
#endif

// ASSERT LV�ɉ�����assert
#ifndef ASSERT_LV
#define ASSERT_LV 0
#endif

#define ASSERT_LV_EX(L, X) { if (L <= ASSERT_LV) ASSERT(X); }
#define ASSERT_LV1(X) ASSERT_LV_EX(1, X)
#define ASSERT_LV2(X) ASSERT_LV_EX(2, X)
#define ASSERT_LV3(X) ASSERT_LV_EX(3, X)
#define ASSERT_LV4(X) ASSERT_LV_EX(4, X)
#define ASSERT_LV5(X) ASSERT_LV_EX(5, X)

// --- declaration of unreachablity

// switch�ɂ�����default�ɓ��B���Ȃ����Ƃ𖾎����č�����������

// �f�o�b�O���͕��ʂɂ��Ƃ��Ȃ��ƕςȃA�h���X�ɃW�����v���Č��������Ɏ��Ԃ�������B
#if defined(_MSC_VER)
#define UNREACHABLE ASSERT_LV3(false); __assume(0);
#elif defined(__GNUC__)
#define UNREACHABLE ASSERT_LV3(false); __builtin_unreachable();
#else
#define UNREACHABLE ASSERT_LV3(false);
#endif

// --- alignment tools

// �\���̂Ȃǂ̃A���C�����g�𑵂��邽�߂̐錾�q

#if defined(_MSC_VER)
#define ALIGNED(X) __declspec(align(X))
#elif defined(__GNUC__)
#define ALIGNED(X) __attribute__ ((aligned(X)))
#else
#define ALIGNED(X) 
#endif

// --- for linux

#if !defined(_MSC_VER)
// stricmp��linux�n�ł͑��݂��Ȃ��炵���A�u��������B
#define _stricmp strcasecmp

// ���ƁAgetline()�����Ƃ��Ƀe�L�X�g�t�@�C����'\r\n'����
// '\r'�������Ɏc��̂ł���'\r'���������邽�߂�wrapper�������B
// ���̂��߁Afstream�ɑ΂���getline()���Ăяo���Ƃ��́A
// std::getline()�ł͂Ȃ��P��getline()�Ə����āA���̊֐����g���ׂ��B
inline bool getline(std::fstream& fs, std::string& s)
{
	bool b = (bool)std::getline(fs, s);
	if (s.size() && s[s.size() - 1] == '\r')
		s.erase(s.size() - 1);
	return b;
}

#endif

// --- output for Japanese notation

// PRETTY_JP����`����Ă��邩�ǂ����ɂ���ĎO�����Z�q�Ȃǂ��g�������̂ŁB
#if defined (PRETTY_JP)
constexpr bool pretty_jp = true;
#else
constexpr bool pretty_jp = false;
#endif


// --- hash key bits

#if HASH_KEY_BITS <= 64
#define HASH_KEY Key64
#elif HASH_KEY_BITS <= 128
#define HASH_KEY Key128
#else
#define HASH_KEY Key256
#endif

// --- Dropbit

// USE_DROPBIT_IN_STATS��define����Ă���Ƃ��́AMove�̏��16bit�Ɋi�[����Piece�Ƃ��ċ�ł��� +32(PIECE_DROP)�@�ɂ���B
#ifdef USE_DROPBIT_IN_STATS
#define PIECE_DROP 32
#else
#define PIECE_DROP 0
#endif

// --- lastMove

// KIF�`���ɕϊ�����Ƃ���Position�N���X�ɂ��̋ǖʂ֎��钼�O�̎w���肪�ۑ�����Ă��Ȃ���
// "��"���̂悤�ɏo�͂ł��Ȃ��č���B
#ifdef USE_KIF_CONVERT_TOOLS
#define KEEP_LAST_MOVE
#endif

// ----------------------------
//      CPU environment
// ----------------------------

// �^�[�Q�b�g��64bitOS���ǂ���
#if (defined(_WIN64) && defined(_MSC_VER)) || (defined(__GNUC__) && defined(__x86_64__))
constexpr bool Is64Bit = true;
#define IS_64BIT
#else
constexpr bool Is64Bit = false;
#endif

#if defined(USE_AVX512)
#define TARGET_CPU "AVX-512"
#elif defined(USE_AVX2)
#define TARGET_CPU "AVX2"
#elif defined(USE_SSE42)
#define TARGET_CPU "SSE4.2"
#elif defined(USE_SSE41)
#define TARGET_CPU "SSE4.1"
#elif defined(USE_SSE2)
#define TARGET_CPU "SSE2"
#else
#define TARGET_CPU "noSSE"
#endif

// ��ʂ�CPU���^�[�Q�b�g�Ƃ���Ȃ�A���̉���CPU�̖��߂͂��ׂĎg����͂��Ȃ̂Łc�B

#ifdef USE_AVX512
#define USE_AVX2
#endif

#ifdef USE_AVX2
#define USE_SSE42
#endif

#ifdef USE_SSE42
#define USE_SSE41
#endif

#ifdef USE_SSE41
#define USE_SSE2
#endif

// --------------------
//    for 32bit OS
// --------------------

#if !defined(IS_64BIT)

// 32bit���ł̓�����������Ȃ��Ȃ�̂ňȉ���2�͋����I�ɃI�t�ɂ��Ă����B

#undef USE_EVAL_HASH
#undef USE_SHARED_MEMORY_IN_EVAL

// �@�B�w�K�p�̔z�����������ԂɎ��܂肫��Ȃ��̂ŃR���p�C���G���[�ƂȂ邩��
// ������I�t�ɂ��Ă����B
#undef EVAL_LEARN

#endif

// ----------------------------
//     mutex wrapper
// ----------------------------

// Windows�p��mingw�Agcc������std::mutex�������Ƒ��������ɍ����ւ��������̂��߂�wrap���Ă���B
// ���̂���std::mutex�Astd::condition_variable�𒼐ڗp����̂ł͂Ȃ��AMutex�AConditionVariable��p����B

#include "thread_win32.h"

// ----------------------------
//     mkdir wrapper
// ----------------------------

// �J�����g�t�H���_���΂Ŏw�肷��B���������0�A���s����Δ�0���Ԃ�B
// �t�H���_���쐬����B���{��͎g���Ă��Ȃ����̂Ƃ���B
// �ǂ���msys2������gcc����_wmkdir()���ƃt�H���_�̍쐬�Ɏ��s����B�����s���B
// �d���Ȃ��̂�_mkdir()��p����B

#if defined(_WIN32)
// Windows�p

#if defined(_MSC_VER)
#include <codecvt>	// mkdir����̂�wstring���~�����̂ł��ꂪ�K�v
#include <locale>   // wstring_convert�ɂ��ꂪ�K�v�B
inline int MKDIR(std::string dir_name)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> cv;
	return _wmkdir(cv.from_bytes(dir_name).c_str());
//	::CreateDirectory(cv.from_bytes(dir_name).c_str(),NULL);
}
#elif defined(__GNUC__) 
#include <direct.h>
inline int MKDIR(std::string dir_name)
{
	return _mkdir(dir_name.c_str());
}
#endif
#elif defined(_LINUX)
// linux���ɂ����āA����_LINUX�Ƃ����V���{����makefile�ɂĒ�`�������̂Ƃ���B

// Linux�p��mkdir�����B
#include "sys/stat.h"

inline int MKDIR(std::string dir_name)
{
	return ::mkdir(dir_name.c_str(), 0777);
}

#else

// Linux�����ǂ����𔻒肷�邽�߂ɂ�makefile�𕪂��Ȃ��Ƃ����Ȃ��Ȃ��Ă����..
// linux�Ńt�H���_�@��@�\�́A�Ƃ肠�����i�V�ł�����..�B�]���֐��t�@�C���̕ۑ��ɂ����g���ĂȂ����c�B
inline int MKDIR(std::string dir_name)
{
	return 0;
}

#endif


// ----------------------------
//     evaluate function
// ----------------------------

// -- �]���֐��̎�ނɂ��G���W�����Ɏg�p���镶�����ύX����B
#if defined(EVAL_MATERIAL)
#define EVAL_TYPE_NAME "Material"
#elif defined(EVAL_KPPT)
#define EVAL_TYPE_NAME "KPPT"
#elif defined(EVAL_KPP_KKPT)
#define EVAL_TYPE_NAME "KPP_KKPT"
#elif defined(EVAL_KPPPT)
#define EVAL_TYPE_NAME "KPPPT"
#elif defined(EVAL_KPPP_KKPT)
#define EVAL_TYPE_NAME "KPPP_KKPT"
#elif defined(EVAL_KKPP_KKPT)
#define EVAL_TYPE_NAME "KKPP_KKPT"
#elif defined(EVAL_KKPPT)
#define EVAL_TYPE_NAME "KKPPT"
#elif defined(EVAL_KPP_KKPT_FV_VAR)
#define EVAL_TYPE_NAME "KPP_KKPT_FV_VAR"
#elif defined(EVAL_NABLA)
#define EVAL_TYPE_NAME "NABLA V2"
#elif defined(EVAL_NNUE)
#define EVAL_TYPE_NAME "NNUE"
#else
#define EVAL_TYPE_NAME ""
#endif

// -- do_move()�̂Ƃ��Ɉړ�������̊Ǘ������č����v�Z

// 1. ��ԍ����Ǘ����Ă���piece_list�ɂ���
//   �����Position::eval_list()�Ŏ擾�\�B
// 2. �ړ�������̊Ǘ��ɂ���
//   ����́APosition::state()->dirtyPiece�B
//   FV38���ƍő��2�B
//   FV_VAR����n��(��)�B
// 3. FV38���Ƃ����ԍ������̋�ł��邩�����܂��Ă���B(PieceNumber�^)
// 4. FV_VAR���Ƃ����ԍ������̋�ł��邩�͒�܂��Ă��Ȃ��B�K�v�ȋ����eval_list()�Ɋi�[����Ă���B
//    ����̏ꍇ�ABonaPieceZero�͎g���Ȃ��B(�K�v�Ȃ����eval_list()�Ɋi�[����Ă��Ȃ����߁B)
//    �܂��A��10���̂悤�ɓ���̋��̋�𑝂₷���Ƃɂ��Ή��ł���B(EvalList::MAX_LENGTH��ύX����K�v�͂��邪�B)
// 5. FV38��FV_VAR���ǂ��炩��I�����Ȃ���΂Ȃ�Ȃ��B
//    �{���Ȃ�A���̂ǂ�����p���Ȃ��悤�ɂ��o����Ɨǂ��̂����A�\�[�X�R�[�h�������Ⴎ����ɂȂ�̂ł���͂��Ȃ����Ƃɂ����B
// 6. FV_VAR�����́APosition::do_move()�ł�piece_list�͍X�V���ꂸ�AdirtyPiece�̏��݂̂��X�V�����B
//    �䂦�ɁAevaluate()�ł�dirtyPiece�̏��Ɋ�Â��Apiece_list�̍X�V�����Ȃ���΂Ȃ�Ȃ��B
//    ���@DirtyPiece::do_update()�Ȃǂ����邱�ƁB
//    �܂��Ainv_piece()��p����̂ŁA�]���֐��̏������^�C�~���O��EvalLearningTools::init_mir_inv_tables()���Ăяo����
//    inv_piece()���g�����Ԃɂ��Ă����Ȃ���΂Ȃ�Ȃ��B
// 7. FV_VAR�����̃��t�@�����X�����Ƃ��āAEVAL_KPP_KKPT_FV_VAR������̂ŁA���̃\�[�X�R�[�h�����邱�ƁB

// ������ǖʂ�P(��)�̐��������Ȃ�FV38�ƌĂ΂��`���̍����v�Z�p�B
#if defined(EVAL_KPPT) || defined(EVAL_KPP_KKPT) || defined(EVAL_KPPPT) || defined(EVAL_KPPP_KKPT) || defined(EVAL_KKPP_KKPT) || defined(EVAL_KKPPT) || defined(EVAL_HELICES) || defined(EVAL_NNUE)
#define USE_FV38
#endif

// P(��)�̐����������茸�����肷��^�C�v�̍����v�Z�p
// FV38�Ƃ͈قȂ�A�ϒ�piece_list�B
#if defined(EVAL_MATERIAL) || defined(EVAL_KPP_KKPT_FV_VAR) || defined(EVAL_NABLA)
#define USE_FV_VAR
#endif

// -- �]���֐��̎�ނɂ��A�Ֆʂ̗����̍X�V�Ƃ��̏������قȂ�B(���̃^�C�~���O�ŕ]���֐��̍����v�Z���������̂�)

// �Ֆʏ�̗������X�V����Ƃ��ɌĂяo�������֐��B(�]���֐��̍����X�V�Ȃǂ̂��߂ɍ����ւ��\�ɂ��Ă����B)

// color = ��� , sq = �� , e = �����̉��Z��
#define ADD_BOARD_EFFECT(color_,sq_,e1_) { board_effect[color_].e[sq_] += (uint8_t)e1_; }
// e1 = color���̗����̉��Z�� , e2 = ~color���̗����̉��Z��
#define ADD_BOARD_EFFECT_BOTH(color_,sq_,e1_,e2_) { board_effect[color_].e[sq_] += (uint8_t)e1_; board_effect[~color_].e[sq_] += (uint8_t)e2_; }

// ���̊֐���undo_move()���p�B������́A�]���֐��̍����X�V���s��Ȃ��B(�]���֐��̒l�������߂��̂͊ȒP�ł��邽��)
#define ADD_BOARD_EFFECT_REWIND(color_,sq_,e1_) { board_effect[color_].e[sq_] += (uint8_t)e1_; }
#define ADD_BOARD_EFFECT_BOTH_REWIND(color_,sq_,e1_,e2_) { board_effect[color_].e[sq_] += (uint8_t)e1_; board_effect[~color_].e[sq_] += (uint8_t)e2_; }

#endif // _CONFIG_H_
