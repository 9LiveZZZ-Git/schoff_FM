/* ------------------------------------------------------------
name: "effect"
Code generated with Faust 2.83.1 (https://faust.grame.fr)
Compilation options: -lang cpp -fpga-mem-th 4 -ct 1 -cn effect -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __effect_H__
#define  __effect_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
#include <algorithm>
#include <cmath>
#include <cstdint>
#include <math.h>

#ifndef FAUSTCLASS 
#define FAUSTCLASS effect
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

class effectSIG0 {
	
  private:
	
	int iVec6[2];
	int iRec13[2];
	
  public:
	
	int getNumInputseffectSIG0() {
		return 0;
	}
	int getNumOutputseffectSIG0() {
		return 1;
	}
	
	void instanceIniteffectSIG0(int sample_rate) {
		for (int l9 = 0; l9 < 2; l9 = l9 + 1) {
			iVec6[l9] = 0;
		}
		for (int l10 = 0; l10 < 2; l10 = l10 + 1) {
			iRec13[l10] = 0;
		}
	}
	
	void filleffectSIG0(int count, float* table) {
		for (int i1 = 0; i1 < count; i1 = i1 + 1) {
			iVec6[0] = 1;
			iRec13[0] = (iVec6[1] + iRec13[1]) % 65536;
			table[i1] = std::sin(9.58738e-05f * static_cast<float>(iRec13[0]));
			iVec6[1] = iVec6[0];
			iRec13[1] = iRec13[0];
		}
	}

};

static effectSIG0* neweffectSIG0() { return (effectSIG0*)new effectSIG0(); }
static void deleteeffectSIG0(effectSIG0* dsp) { delete dsp; }

const static int ieffectSIG1Wave0[2048] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079,3083,3089,3109,3119,3121,3137,3163,3167,3169,3181,3187,3191,3203,3209,3217,3221,3229,3251,3253,3257,3259,3271,3299,3301,3307,3313,3319,3323,3329,3331,3343,3347,3359,3361,3371,3373,3389,3391,3407,3413,3433,3449,3457,3461,3463,3467,3469,3491,3499,3511,3517,3527,3529,3533,3539,3541,3547,3557,3559,3571,3581,3583,3593,3607,3613,3617,3623,3631,3637,3643,3659,3671,3673,3677,3691,3697,3701,3709,3719,3727,3733,3739,3761,3767,3769,3779,3793,3797,3803,3821,3823,3833,3847,3851,3853,3863,3877,3881,3889,3907,3911,3917,3919,3923,3929,3931,3943,3947,3967,3989,4001,4003,4007,4013,4019,4021,4027,4049,4051,4057,4073,4079,4091,4093,4099,4111,4127,4129,4133,4139,4153,4157,4159,4177,4201,4211,4217,4219,4229,4231,4241,4243,4253,4259,4261,4271,4273,4283,4289,4297,4327,4337,4339,4349,4357,4363,4373,4391,4397,4409,4421,4423,4441,4447,4451,4457,4463,4481,4483,4493,4507,4513,4517,4519,4523,4547,4549,4561,4567,4583,4591,4597,4603,4621,4637,4639,4643,4649,4651,4657,4663,4673,4679,4691,4703,4721,4723,4729,4733,4751,4759,4783,4787,4789,4793,4799,4801,4813,4817,4831,4861,4871,4877,4889,4903,4909,4919,4931,4933,4937,4943,4951,4957,4967,4969,4973,4987,4993,4999,5003,5009,5011,5021,5023,5039,5051,5059,5077,5081,5087,5099,5101,5107,5113,5119,5147,5153,5167,5171,5179,5189,5197,5209,5227,5231,5233,5237,5261,5273,5279,5281,5297,5303,5309,5323,5333,5347,5351,5381,5387,5393,5399,5407,5413,5417,5419,5431,5437,5441,5443,5449,5471,5477,5479,5483,5501,5503,5507,5519,5521,5527,5531,5557,5563,5569,5573,5581,5591,5623,5639,5641,5647,5651,5653,5657,5659,5669,5683,5689,5693,5701,5711,5717,5737,5741,5743,5749,5779,5783,5791,5801,5807,5813,5821,5827,5839,5843,5849,5851,5857,5861,5867,5869,5879,5881,5897,5903,5923,5927,5939,5953,5981,5987,6007,6011,6029,6037,6043,6047,6053,6067,6073,6079,6089,6091,6101,6113,6121,6131,6133,6143,6151,6163,6173,6197,6199,6203,6211,6217,6221,6229,6247,6257,6263,6269,6271,6277,6287,6299,6301,6311,6317,6323,6329,6337,6343,6353,6359,6361,6367,6373,6379,6389,6397,6421,6427,6449,6451,6469,6473,6481,6491,6521,6529,6547,6551,6553,6563,6569,6571,6577,6581,6599,6607,6619,6637,6653,6659,6661,6673,6679,6689,6691,6701,6703,6709,6719,6733,6737,6761,6763,6779,6781,6791,6793,6803,6823,6827,6829,6833,6841,6857,6863,6869,6871,6883,6899,6907,6911,6917,6947,6949,6959,6961,6967,6971,6977,6983,6991,6997,7001,7013,7019,7027,7039,7043,7057,7069,7079,7103,7109,7121,7127,7129,7151,7159,7177,7187,7193,7207,7211,7213,7219,7229,7237,7243,7247,7253,7283,7297,7307,7309,7321,7331,7333,7349,7351,7369,7393,7411,7417,7433,7451,7457,7459,7477,7481,7487,7489,7499,7507,7517,7523,7529,7537,7541,7547,7549,7559,7561,7573,7577,7583,7589,7591,7603,7607,7621,7639,7643,7649,7669,7673,7681,7687,7691,7699,7703,7717,7723,7727,7741,7753,7757,7759,7789,7793,7817,7823,7829,7841,7853,7867,7873,7877,7879,7883,7901,7907,7919,7927,7933,7937,7949,7951,7963,7993,8009,8011,8017,8039,8053,8059,8069,8081,8087,8089,8093,8101,8111,8117,8123,8147,8161,8167,8171,8179,8191,8209,8219,8221,8231,8233,8237,8243,8263,8269,8273,8287,8291,8293,8297,8311,8317,8329,8353,8363,8369,8377,8387,8389,8419,8423,8429,8431,8443,8447,8461,8467,8501,8513,8521,8527,8537,8539,8543,8563,8573,8581,8597,8599,8609,8623,8627,8629,8641,8647,8663,8669,8677,8681,8689,8693,8699,8707,8713,8719,8731,8737,8741,8747,8753,8761,8779,8783,8803,8807,8819,8821,8831,8837,8839,8849,8861,8863,8867,8887,8893,8923,8929,8933,8941,8951,8963,8969,8971,8999,9001,9007,9011,9013,9029,9041,9043,9049,9059,9067,9091,9103,9109,9127,9133,9137,9151,9157,9161,9173,9181,9187,9199,9203,9209,9221,9227,9239,9241,9257,9277,9281,9283,9293,9311,9319,9323,9337,9341,9343,9349,9371,9377,9391,9397,9403,9413,9419,9421,9431,9433,9437,9439,9461,9463,9467,9473,9479,9491,9497,9511,9521,9533,9539,9547,9551,9587,9601,9613,9619,9623,9629,9631,9643,9649,9661,9677,9679,9689,9697,9719,9721,9733,9739,9743,9749,9767,9769,9781,9787,9791,9803,9811,9817,9829,9833,9839,9851,9857,9859,9871,9883,9887,9901,9907,9923,9929,9931,9941,9949,9967,9973,10007,10009,10037,10039,10061,10067,10069,10079,10091,10093,10099,10103,10111,10133,10139,10141,10151,10159,10163,10169,10177,10181,10193,10211,10223,10243,10247,10253,10259,10267,10271,10273,10289,10301,10303,10313,10321,10331,10333,10337,10343,10357,10369,10391,10399,10427,10429,10433,10453,10457,10459,10463,10477,10487,10499,10501,10513,10529,10531,10559,10567,10589,10597,10601,10607,10613,10627,10631,10639,10651,10657,10663,10667,10687,10691,10709,10711,10723,10729,10733,10739,10753,10771,10781,10789,10799,10831,10837,10847,10853,10859,10861,10867,10883,10889,10891,10903,10909,10937,10939,10949,10957,10973,10979,10987,10993,11003,11027,11047,11057,11059,11069,11071,11083,11087,11093,11113,11117,11119,11131,11149,11159,11161,11171,11173,11177,11197,11213,11239,11243,11251,11257,11261,11273,11279,11287,11299,11311,11317,11321,11329,11351,11353,11369,11383,11393,11399,11411,11423,11437,11443,11447,11467,11471,11483,11489,11491,11497,11503,11519,11527,11549,11551,11579,11587,11593,11597,11617,11621,11633,11657,11677,11681,11689,11699,11701,11717,11719,11731,11743,11777,11779,11783,11789,11801,11807,11813,11821,11827,11831,11833,11839,11863,11867,11887,11897,11903,11909,11923,11927,11933,11939,11941,11953,11959,11969,11971,11981,11987,12007,12011,12037,12041,12043,12049,12071,12073,12097,12101,12107,12109,12113,12119,12143,12149,12157,12161,12163,12197,12203,12211,12227,12239,12241,12251,12253,12263,12269,12277,12281,12289,12301,12323,12329,12343,12347,12373,12377,12379,12391,12401,12409,12413,12421,12433,12437,12451,12457,12473,12479,12487,12491,12497,12503,12511,12517,12527,12539,12541,12547,12553,12569,12577,12583,12589,12601,12611,12613,12619,12637,12641,12647,12653,12659,12671,12689,12697,12703,12713,12721,12739,12743,12757,12763,12781,12791,12799,12809,12821,12823,12829,12841,12853,12889,12893,12899,12907,12911,12917,12919,12923,12941,12953,12959,12967,12973,12979,12983,13001,13003,13007,13009,13033,13037,13043,13049,13063,13093,13099,13103,13109,13121,13127,13147,13151,13159,13163,13171,13177,13183,13187,13217,13219,13229,13241,13249,13259,13267,13291,13297,13309,13313,13327,13331,13337,13339,13367,13381,13397,13399,13411,13417,13421,13441,13451,13457,13463,13469,13477,13487,13499,13513,13523,13537,13553,13567,13577,13591,13597,13613,13619,13627,13633,13649,13669,13679,13681,13687,13691,13693,13697,13709,13711,13721,13723,13729,13751,13757,13759,13763,13781,13789,13799,13807,13829,13831,13841,13859,13873,13877,13879,13883,13901,13903,13907,13913,13921,13931,13933,13963,13967,13997,13999,14009,14011,14029,14033,14051,14057,14071,14081,14083,14087,14107,14143,14149,14153,14159,14173,14177,14197,14207,14221,14243,14249,14251,14281,14293,14303,14321,14323,14327,14341,14347,14369,14387,14389,14401,14407,14411,14419,14423,14431,14437,14447,14449,14461,14479,14489,14503,14519,14533,14537,14543,14549,14551,14557,14561,14563,14591,14593,14621,14627,14629,14633,14639,14653,14657,14669,14683,14699,14713,14717,14723,14731,14737,14741,14747,14753,14759,14767,14771,14779,14783,14797,14813,14821,14827,14831,14843,14851,14867,14869,14879,14887,14891,14897,14923,14929,14939,14947,14951,14957,14969,14983,15013,15017,15031,15053,15061,15073,15077,15083,15091,15101,15107,15121,15131,15137,15139,15149,15161,15173,15187,15193,15199,15217,15227,15233,15241,15259,15263,15269,15271,15277,15287,15289,15299,15307,15313,15319,15329,15331,15349,15359,15361,15373,15377,15383,15391,15401,15413,15427,15439,15443,15451,15461,15467,15473,15493,15497,15511,15527,15541,15551,15559,15569,15581,15583,15601,15607,15619,15629,15641,15643,15647,15649,15661,15667,15671,15679,15683,15727,15731,15733,15737,15739,15749,15761,15767,15773,15787,15791,15797,15803,15809,15817,15823,15859,15877,15881,15887,15889,15901,15907,15913,15919,15923,15937,15959,15971,15973,15991,16001,16007,16033,16057,16061,16063,16067,16069,16073,16087,16091,16097,16103,16111,16127,16139,16141,16183,16187,16189,16193,16217,16223,16229,16231,16249,16253,16267,16273,16301,16319,16333,16339,16349,16361,16363,16369,16381,16411,16417,16421,16427,16433,16447,16451,16453,16477,16481,16487,16493,16519,16529,16547,16553,16561,16567,16573,16603,16607,16619,16631,16633,16649,16651,16657,16661,16673,16691,16693,16699,16703,16729,16741,16747,16759,16763,16787,16811,16823,16829,16831,16843,16871,16879,16883,16889,16901,16903,16921,16927,16931,16937,16943,16963,16979,16981,16987,16993,17011,17021,17027,17029,17033,17041,17047,17053,17077,17093,17099,17107,17117,17123,17137,17159,17167,17183,17189,17191,17203,17207,17209,17231,17239,17257,17291,17293,17299,17317,17321,17327,17333,17341,17351,17359,17377,17383,17387,17389,17393,17401,17417,17419,17431,17443,17449,17467,17471,17477,17483,17489,17491,17497,17509,17519,17539,17551,17569,17573,17579,17581,17597,17599,17609,17623,17627,17657,17659,17669,17681,17683,17707,17713,17729,17737,17747,17749,17761,17783,17789,17791,17807,17827,17837,17839,17851,17863};
class effectSIG1 {
	
  private:
	
	int ieffectSIG1Wave0_idx;
	
  public:
	
	int getNumInputseffectSIG1() {
		return 0;
	}
	int getNumOutputseffectSIG1() {
		return 1;
	}
	
	void instanceIniteffectSIG1(int sample_rate) {
		ieffectSIG1Wave0_idx = 0;
	}
	
	void filleffectSIG1(int count, int* table) {
		for (int i2 = 0; i2 < count; i2 = i2 + 1) {
			table[i2] = ieffectSIG1Wave0[ieffectSIG1Wave0_idx];
			ieffectSIG1Wave0_idx = (1 + ieffectSIG1Wave0_idx) % 2048;
		}
	}

};

static effectSIG1* neweffectSIG1() { return (effectSIG1*)new effectSIG1(); }
static void deleteeffectSIG1(effectSIG1* dsp) { delete dsp; }

static float effect_faustpower2_f(float value) {
	return value * value;
}
static float ftbl0effectSIG0[65536];
static int itbl1effectSIG1[2048];

class effect : public base_dsp {
	
 private:
	
	FAUSTFLOAT fEntry0;
	int iVec0[2];
	int iVec1[2];
	FAUSTFLOAT fHslider0;
	float fVec2[2];
	float fVec3[2];
	float fRec9[2];
	FAUSTFLOAT fHslider1;
	int IOTA0;
	FAUSTFLOAT fHslider2;
	int fSampleRate;
	float fConst0;
	float fVec4[2];
	FAUSTFLOAT fHslider3;
	float fConst1;
	float fRec11[2];
	FAUSTFLOAT fHslider4;
	FAUSTFLOAT fHslider5;
	float fRec12[3];
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fVec5[4096];
	FAUSTFLOAT fHslider8;
	float fConst2;
	float fRec14[2];
	FAUSTFLOAT fHslider9;
	float fConst3;
	float fRec15[2];
	FAUSTFLOAT fHslider10;
	float fRec10[131072];
	FAUSTFLOAT fHslider11;
	float fVec7[8192];
	int iConst4;
	int iConst5;
	float fRec8[2];
	float fRec17[2];
	float fVec8[8192];
	int iConst6;
	int iConst7;
	float fRec16[2];
	float fRec19[2];
	float fVec9[8192];
	int iConst8;
	int iConst9;
	float fRec18[2];
	float fRec21[2];
	float fVec10[8192];
	int iConst10;
	int iConst11;
	float fRec20[2];
	float fRec23[2];
	float fVec11[8192];
	int iConst12;
	int iConst13;
	float fRec22[2];
	float fRec25[2];
	float fVec12[8192];
	int iConst14;
	int iConst15;
	float fRec24[2];
	float fRec27[2];
	float fVec13[8192];
	int iConst16;
	int iConst17;
	float fRec26[2];
	float fRec29[2];
	float fVec14[8192];
	int iConst18;
	int iConst19;
	float fRec28[2];
	float fVec15[2048];
	int iConst20;
	int iConst21;
	float fRec6[2];
	float fVec16[2048];
	int iConst22;
	int iConst23;
	float fRec4[2];
	float fVec17[2048];
	int iConst24;
	int iConst25;
	float fRec2[2];
	float fVec18[1024];
	int iConst26;
	int iConst27;
	float fRec0[2];
	float fConst28;
	float fConst29;
	float fConst30;
	float fConst31;
	float fConst32;
	float fConst33;
	float fConst34;
	float fRec41[2];
	float fConst35;
	float fRec40[2];
	float fVec19[16384];
	float fConst36;
	int iConst37;
	float fConst38;
	float fVec20[2];
	float fRec43[2];
	float fRec44[3];
	float fVec21[4096];
	float fConst39;
	float fRec45[2];
	float fRec42[131072];
	float fVec22[16384];
	int iConst40;
	float fVec23[4096];
	int iConst41;
	float fRec38[2];
	float fConst42;
	float fConst43;
	float fConst44;
	float fRec49[2];
	float fConst45;
	float fRec48[2];
	float fVec24[16384];
	float fConst46;
	int iConst47;
	float fVec25[2048];
	int iConst48;
	float fRec46[2];
	float fConst49;
	float fConst50;
	float fConst51;
	float fRec53[2];
	float fConst52;
	float fRec52[2];
	float fVec26[16384];
	float fConst53;
	int iConst54;
	float fVec27[4096];
	int iConst55;
	float fRec50[2];
	float fConst56;
	float fConst57;
	float fConst58;
	float fRec57[2];
	float fConst59;
	float fRec56[2];
	float fVec28[16384];
	float fConst60;
	int iConst61;
	float fVec29[2048];
	int iConst62;
	float fRec54[2];
	float fConst63;
	float fConst64;
	float fConst65;
	float fRec61[2];
	float fConst66;
	float fRec60[2];
	float fVec30[32768];
	float fConst67;
	int iConst68;
	float fVec31[4096];
	int iConst69;
	float fRec58[2];
	float fConst70;
	float fConst71;
	float fConst72;
	float fRec65[2];
	float fConst73;
	float fRec64[2];
	float fVec32[16384];
	float fConst74;
	int iConst75;
	float fVec33[4096];
	int iConst76;
	float fRec62[2];
	float fConst77;
	float fConst78;
	float fConst79;
	float fRec69[2];
	float fConst80;
	float fRec68[2];
	float fVec34[32768];
	float fConst81;
	int iConst82;
	float fVec35[4096];
	int iConst83;
	float fRec66[2];
	float fConst84;
	float fConst85;
	float fConst86;
	float fRec73[2];
	float fConst87;
	float fRec72[2];
	float fVec36[32768];
	float fConst88;
	int iConst89;
	float fVec37[2048];
	int iConst90;
	float fRec70[2];
	float fRec30[3];
	float fRec31[3];
	float fRec32[3];
	float fRec33[3];
	float fRec34[3];
	float fRec35[3];
	float fRec36[3];
	float fRec37[3];
	float fVec38[1024];
	float fRec79[2];
	float fVec39[8192];
	float fRec78[2];
	float fVec40[4096];
	float fRec76[2];
	float fVec41[4096];
	float fRec89[3];
	float fVec42[256];
	float fRec87[2];
	float fVec43[128];
	float fRec85[2];
	float fVec44[512];
	float fRec83[2];
	float fVec45[512];
	float fRec81[2];
	float fRec74[2];
	float fVec46[1024];
	float fRec93[2];
	float fVec47[8192];
	float fRec92[2];
	float fVec48[2048];
	float fRec90[2];
	float fVec49[2048];
	float fRec75[2];
	float fConst91;
	float fConst92;
	float fConst93;
	float fConst94;
	float fConst95;
	float fConst96;
	float fConst97;
	float fConst98;
	float fConst99;
	float fConst100;
	float fConst101;
	float fConst102;
	float fConst103;
	float fConst104;
	float fConst105;
	float fConst106;
	float fConst107;
	float fConst108;
	float fConst109;
	float fConst110;
	float fRec105[2];
	float fRec107[2];
	float fRec111[2];
	float fVec50[16384];
	float fVec51[2];
	float fRec110[2];
	float fRec108[2];
	float fRec113[2];
	float fVec52[16384];
	float fVec53[2];
	float fRec112[2];
	float fRec109[2];
	float fRec117[2];
	float fVec54[16384];
	float fVec55[2];
	float fRec116[2];
	float fRec114[2];
	float fRec119[2];
	float fVec56[16384];
	float fVec57[2];
	float fRec118[2];
	float fRec115[2];
	float fRec123[2];
	float fVec58[16384];
	float fVec59[2];
	float fRec122[2];
	float fRec120[2];
	float fRec125[2];
	float fVec60[16384];
	float fVec61[2];
	float fRec124[2];
	float fRec121[2];
	float fRec129[2];
	float fVec62[16384];
	float fVec63[2];
	float fRec128[2];
	float fRec126[2];
	float fRec131[2];
	float fVec64[16384];
	float fVec65[2];
	float fRec130[2];
	float fRec127[2];
	float fRec135[2];
	float fVec66[16384];
	float fVec67[2];
	float fRec134[2];
	float fRec132[2];
	float fRec137[2];
	float fVec68[16384];
	float fVec69[2];
	float fRec136[2];
	float fRec133[2];
	float fVec70[1024];
	float fConst111;
	float fConst112;
	float fConst113;
	float fRec138[2];
	float fRec139[2];
	FAUSTFLOAT fHslider12;
	float fVec71[2];
	float fVec72[16384];
	float fVec73[2];
	float fRec106[2];
	float fRec143[2];
	float fRec145[2];
	float fVec74[1024];
	float fVec75[16384];
	float fVec76[2];
	float fRec144[2];
	float fVec77[16384];
	float fVec78[2];
	float fRec142[2];
	float fRec140[2];
	float fRec147[2];
	float fVec79[16384];
	float fVec80[2];
	float fRec146[2];
	float fRec141[2];
	float fRec151[2];
	float fVec81[16384];
	float fVec82[2];
	float fRec150[2];
	float fRec148[2];
	float fRec153[2];
	float fVec83[16384];
	float fVec84[2];
	float fRec152[2];
	float fRec149[2];
	float fRec157[2];
	float fVec85[16384];
	float fVec86[2];
	float fRec156[2];
	float fRec154[2];
	float fRec159[2];
	float fVec87[16384];
	float fVec88[2];
	float fRec158[2];
	float fRec155[2];
	float fRec163[2];
	float fVec89[16384];
	float fVec90[2];
	float fRec162[2];
	float fRec160[2];
	float fRec165[2];
	float fVec91[16384];
	float fVec92[2];
	float fRec164[2];
	float fRec161[2];
	float fRec169[2];
	float fVec93[16384];
	float fVec94[2];
	float fRec168[2];
	float fRec166[2];
	float fRec171[2];
	float fVec95[16384];
	float fVec96[2];
	float fRec170[2];
	float fRec167[2];
	float fVec97[16384];
	float fVec98[16384];
	float fVec99[2];
	float fRec104[2];
	float fConst114;
	float fConst115;
	float fRec103[2];
	float fRec102[3];
	float fRec101[3];
	float fVec100[2];
	float fConst116;
	float fConst117;
	float fConst118;
	float fRec100[2];
	float fRec99[3];
	float fConst119;
	float fRec98[3];
	float fRec174[2];
	float fRec173[3];
	float fRec172[3];
	float fConst120;
	float fConst121;
	float fRec178[2];
	float fRec177[3];
	float fConst122;
	float fRec176[3];
	float fConst123;
	float fRec175[3];
	float fVec101[1024];
	float fRec97[2];
	float fRec190[2];
	float fVec102[16384];
	float fVec103[16384];
	float fVec104[2];
	float fRec189[2];
	float fRec188[2];
	float fRec187[3];
	float fRec186[3];
	float fVec105[2];
	float fRec185[2];
	float fRec184[3];
	float fRec183[3];
	float fRec193[2];
	float fRec192[3];
	float fRec191[3];
	float fRec197[2];
	float fRec196[3];
	float fRec195[3];
	float fRec194[3];
	float fVec106[1024];
	float fRec182[2];
	float fVec107[16384];
	float fVec108[2];
	float fRec181[2];
	float fRec179[2];
	float fRec199[2];
	float fVec109[16384];
	float fVec110[2];
	float fRec198[2];
	float fRec180[2];
	float fVec111[16384];
	float fVec112[2];
	float fRec202[2];
	float fRec200[2];
	float fVec113[16384];
	float fVec114[2];
	float fRec203[2];
	float fRec201[2];
	float fVec115[16384];
	float fVec116[2];
	float fRec206[2];
	float fRec204[2];
	float fRec208[2];
	float fVec117[16384];
	float fVec118[2];
	float fRec207[2];
	float fRec205[2];
	float fRec212[2];
	float fVec119[16384];
	float fVec120[2];
	float fRec211[2];
	float fRec209[2];
	float fVec121[16384];
	float fVec122[2];
	float fRec213[2];
	float fRec210[2];
	float fRec95[2];
	float fRec96[2];
	float fVec123[2];
	float fRec217[2];
	float fRec218[2];
	float fConst124;
	float fVec124[131072];
	float fRec219[2];
	float fRec220[2];
	float fRec221[2];
	float fRec222[2];
	float fVec125[131072];
	float fRec235[2];
	float fVec126[16384];
	float fVec127[2];
	float fRec234[2];
	float fRec232[2];
	float fRec237[2];
	float fVec128[16384];
	float fVec129[2];
	float fRec236[2];
	float fRec233[2];
	float fVec130[16384];
	float fRec238[2];
	float fVec131[2];
	float fRec231[2];
	float fRec229[2];
	float fRec240[2];
	float fVec132[16384];
	float fVec133[2];
	float fRec239[2];
	float fRec230[2];
	float fVec134[16384];
	float fRec241[2];
	float fVec135[2];
	float fRec228[2];
	float fRec226[2];
	float fRec243[2];
	float fVec136[16384];
	float fVec137[2];
	float fRec242[2];
	float fRec227[2];
	float fVec138[16384];
	float fVec139[2];
	float fRec225[2];
	float fRec223[2];
	float fRec245[2];
	float fVec140[16384];
	float fVec141[2];
	float fRec244[2];
	float fRec224[2];
	float fRec258[2];
	float fVec142[16384];
	float fVec143[2];
	float fRec257[2];
	float fRec255[2];
	float fRec260[2];
	float fVec144[16384];
	float fVec145[2];
	float fRec259[2];
	float fRec256[2];
	float fVec146[16384];
	float fVec147[2];
	float fRec254[2];
	float fRec252[2];
	float fRec262[2];
	float fVec148[16384];
	float fVec149[2];
	float fRec261[2];
	float fRec253[2];
	float fVec150[16384];
	float fRec263[2];
	float fVec151[2];
	float fRec251[2];
	float fRec249[2];
	float fRec265[2];
	float fVec152[16384];
	float fVec153[2];
	float fRec264[2];
	float fRec250[2];
	float fVec154[16384];
	float fRec266[2];
	float fVec155[2];
	float fRec248[2];
	float fRec246[2];
	float fRec268[2];
	float fVec156[16384];
	float fVec157[2];
	float fRec267[2];
	float fRec247[2];
	float fRec281[2];
	float fVec158[16384];
	float fVec159[2];
	float fRec280[2];
	float fRec278[2];
	float fRec283[2];
	float fVec160[16384];
	float fVec161[2];
	float fRec282[2];
	float fRec279[2];
	float fVec162[16384];
	float fRec284[2];
	float fVec163[2];
	float fRec277[2];
	float fRec275[2];
	float fRec286[2];
	float fVec164[16384];
	float fVec165[2];
	float fRec285[2];
	float fRec276[2];
	float fVec166[16384];
	float fRec287[2];
	float fVec167[2];
	float fRec274[2];
	float fRec272[2];
	float fRec289[2];
	float fVec168[16384];
	float fVec169[2];
	float fRec288[2];
	float fRec273[2];
	float fVec170[16384];
	float fRec290[2];
	float fVec171[2];
	float fRec271[2];
	float fRec269[2];
	float fRec292[2];
	float fVec172[16384];
	float fVec173[2];
	float fRec291[2];
	float fRec270[2];
	float fRec216[2];
	float fRec214[1024];
	float fRec293[2];
	float fRec215[1024];
	FAUSTFLOAT fHslider13;
	FAUSTFLOAT fHslider14;
	float fRec303[2];
	float fVec174[8192];
	int iConst125;
	float fRec302[2];
	float fRec305[2];
	float fVec175[8192];
	int iConst126;
	float fRec304[2];
	float fRec307[2];
	float fVec176[8192];
	int iConst127;
	float fRec306[2];
	float fRec309[2];
	float fVec177[8192];
	int iConst128;
	float fRec308[2];
	float fRec311[2];
	float fVec178[8192];
	int iConst129;
	float fRec310[2];
	float fRec313[2];
	float fVec179[8192];
	int iConst130;
	float fRec312[2];
	float fRec315[2];
	float fVec180[8192];
	int iConst131;
	float fRec314[2];
	float fRec317[2];
	float fVec181[8192];
	int iConst132;
	float fRec316[2];
	float fVec182[2048];
	int iConst133;
	float fRec300[2];
	float fVec183[2048];
	int iConst134;
	float fRec298[2];
	float fVec184[2048];
	int iConst135;
	float fRec296[2];
	float fVec185[1024];
	int iConst136;
	float fRec294[2];
	
 public:
	effect() {
	}
	
	effect(const effect&) = default;
	
	virtual ~effect() = default;
	
	effect& operator=(const effect&) = default;
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "1.3.0");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "1.22.0");
		m->declare("compile_options", "-lang cpp -fpga-mem-th 4 -ct 1 -cn effect -es 1 -mcd 16 -mdd 1024 -mdy 33 -single -ftz 0");
		m->declare("delays.lib/fdelay1a:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelay4:author", "Julius O. Smith III");
		m->declare("delays.lib/fdelayltv:author", "Julius O. Smith III");
		m->declare("delays.lib/name", "Faust Delay Library");
		m->declare("delays.lib/version", "1.2.0");
		m->declare("filename", "effect.dsp");
		m->declare("filters.lib/allpass_comb:author", "Julius O. Smith III");
		m->declare("filters.lib/allpass_comb:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/allpass_comb:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/filterbank:author", "Julius O. Smith III");
		m->declare("filters.lib/filterbank:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/filterbank:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/fir:author", "Julius O. Smith III");
		m->declare("filters.lib/fir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/fir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/highpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/highpass_plus_lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/highpass_plus_lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/iir:author", "Julius O. Smith III");
		m->declare("filters.lib/iir:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/iir:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
		m->declare("filters.lib/lowpass0_highpass1:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:author", "Julius O. Smith III");
		m->declare("filters.lib/lowpass:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/lowpass:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/nlf2:author", "Julius O. Smith III");
		m->declare("filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/nlf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf1s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf1s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf1s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/tf2s:author", "Julius O. Smith III");
		m->declare("filters.lib/tf2s:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/tf2s:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.7.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.9.0");
		m->declare("name", "effect");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.6.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("reverbs.lib/dattorro_rev:author", "Jakob Zerbian");
		m->declare("reverbs.lib/dattorro_rev:licence", "MIT-style STK-4.3 license");
		m->declare("reverbs.lib/greyhole:author", "Julian Parker, bug fixes and minor interface changes by Till Bovermann");
		m->declare("reverbs.lib/greyhole:license", "MIT license");
		m->declare("reverbs.lib/jpverb:author", "Julian Parker, bug fixes and minor interface changes by Till Bovermann");
		m->declare("reverbs.lib/jpverb:license", "MIT license");
		m->declare("reverbs.lib/mono_freeverb:author", "Romain Michon");
		m->declare("reverbs.lib/name", "Faust Reverb Library");
		m->declare("reverbs.lib/version", "1.5.1");
		m->declare("routes.lib/hadamard:author", "Remy Muller, revised by Romain Michon");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.6.0");
	}

	virtual int getNumInputs() {
		return 2;
	}
	virtual int getNumOutputs() {
		return 2;
	}
	
	static void classInit(int sample_rate) {
		effectSIG0* sig0 = neweffectSIG0();
		sig0->instanceIniteffectSIG0(sample_rate);
		sig0->filleffectSIG0(65536, ftbl0effectSIG0);
		effectSIG1* sig1 = neweffectSIG1();
		sig1->instanceIniteffectSIG1(sample_rate);
		sig1->filleffectSIG1(2048, itbl1effectSIG1);
		deleteeffectSIG0(sig0);
		deleteeffectSIG1(sig1);
	}
	
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = std::min<float>(1.92e+05f, std::max<float>(1.0f, static_cast<float>(fSampleRate)));
		fConst1 = 3.1415927f / fConst0;
		fConst2 = 1.07f / fConst0;
		fConst3 = 1.0f / fConst0;
		iConst4 = static_cast<int>(0.025306122f * fConst0);
		iConst5 = std::max<int>(0, iConst4 + -1);
		iConst6 = static_cast<int>(0.026938776f * fConst0);
		iConst7 = std::max<int>(0, iConst6 + -1);
		iConst8 = static_cast<int>(0.028956916f * fConst0);
		iConst9 = std::max<int>(0, iConst8 + -1);
		iConst10 = static_cast<int>(0.030748298f * fConst0);
		iConst11 = std::max<int>(0, iConst10 + -1);
		iConst12 = static_cast<int>(0.0322449f * fConst0);
		iConst13 = std::max<int>(0, iConst12 + -1);
		iConst14 = static_cast<int>(0.033809524f * fConst0);
		iConst15 = std::max<int>(0, iConst14 + -1);
		iConst16 = static_cast<int>(0.035306122f * fConst0);
		iConst17 = std::max<int>(0, iConst16 + -1);
		iConst18 = static_cast<int>(0.036666665f * fConst0);
		iConst19 = std::max<int>(0, iConst18 + -1);
		iConst20 = static_cast<int>(0.0126077095f * fConst0);
		iConst21 = std::min<int>(1024, std::max<int>(0, iConst20 + -1));
		iConst22 = static_cast<int>(0.01f * fConst0);
		iConst23 = std::min<int>(1024, std::max<int>(0, iConst22 + -1));
		iConst24 = static_cast<int>(0.0077324263f * fConst0);
		iConst25 = std::min<int>(1024, std::max<int>(0, iConst24 + -1));
		iConst26 = static_cast<int>(0.0051020407f * fConst0);
		iConst27 = std::min<int>(1024, std::max<int>(0, iConst26 + -1));
		fConst28 = std::floor(0.174713f * fConst0 + 0.5f);
		fConst29 = fConst28 / fConst0;
		fConst30 = 8.634694f * fConst29;
		fConst31 = std::cos(25132.742f / fConst0);
		fConst32 = 1.0f / std::tan(628.31854f / fConst0);
		fConst33 = 1.0f - fConst32;
		fConst34 = 1.0f / (fConst32 + 1.0f);
		fConst35 = 6.9077554f * fConst29;
		fConst36 = std::floor(0.022904f * fConst0 + 0.5f);
		iConst37 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst28 - fConst36)));
		fConst38 = 0.75f * fConst0;
		fConst39 = 0.93f / fConst0;
		iConst40 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, 0.06f * fConst0)));
		iConst41 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst36 + -1.0f)));
		fConst42 = std::floor(0.153129f * fConst0 + 0.5f);
		fConst43 = fConst42 / fConst0;
		fConst44 = 8.634694f * fConst43;
		fConst45 = 6.9077554f * fConst43;
		fConst46 = std::floor(0.020346f * fConst0 + 0.5f);
		iConst47 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst42 - fConst46)));
		iConst48 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst46 + -1.0f)));
		fConst49 = std::floor(0.127837f * fConst0 + 0.5f);
		fConst50 = fConst49 / fConst0;
		fConst51 = 8.634694f * fConst50;
		fConst52 = 6.9077554f * fConst50;
		fConst53 = std::floor(0.031604f * fConst0 + 0.5f);
		iConst54 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst49 - fConst53)));
		iConst55 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst53 + -1.0f)));
		fConst56 = std::floor(0.125f * fConst0 + 0.5f);
		fConst57 = fConst56 / fConst0;
		fConst58 = 8.634694f * fConst57;
		fConst59 = 6.9077554f * fConst57;
		fConst60 = std::floor(0.013458f * fConst0 + 0.5f);
		iConst61 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst56 - fConst60)));
		iConst62 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst60 + -1.0f)));
		fConst63 = std::floor(0.210389f * fConst0 + 0.5f);
		fConst64 = fConst63 / fConst0;
		fConst65 = 8.634694f * fConst64;
		fConst66 = 6.9077554f * fConst64;
		fConst67 = std::floor(0.024421f * fConst0 + 0.5f);
		iConst68 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, fConst63 - fConst67)));
		iConst69 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst67 + -1.0f)));
		fConst70 = std::floor(0.192303f * fConst0 + 0.5f);
		fConst71 = fConst70 / fConst0;
		fConst72 = 8.634694f * fConst71;
		fConst73 = 6.9077554f * fConst71;
		fConst74 = std::floor(0.029291f * fConst0 + 0.5f);
		iConst75 = static_cast<int>(std::min<float>(8192.0f, std::max<float>(0.0f, fConst70 - fConst74)));
		iConst76 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst74 + -1.0f)));
		fConst77 = std::floor(0.256891f * fConst0 + 0.5f);
		fConst78 = fConst77 / fConst0;
		fConst79 = 8.634694f * fConst78;
		fConst80 = 6.9077554f * fConst78;
		fConst81 = std::floor(0.027333f * fConst0 + 0.5f);
		iConst82 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, fConst77 - fConst81)));
		iConst83 = static_cast<int>(std::min<float>(2048.0f, std::max<float>(0.0f, fConst81 + -1.0f)));
		fConst84 = std::floor(0.219991f * fConst0 + 0.5f);
		fConst85 = fConst84 / fConst0;
		fConst86 = 8.634694f * fConst85;
		fConst87 = 6.9077554f * fConst85;
		fConst88 = std::floor(0.019123f * fConst0 + 0.5f);
		iConst89 = static_cast<int>(std::min<float>(16384.0f, std::max<float>(0.0f, fConst84 - fConst88)));
		iConst90 = static_cast<int>(std::min<float>(1024.0f, std::max<float>(0.0f, fConst88 + -1.0f)));
		fConst91 = std::tan(1570.7964f / fConst0);
		fConst92 = effect_faustpower2_f(fConst91);
		fConst93 = 1.0f / fConst92;
		fConst94 = 2.0f * (1.0f - fConst93);
		fConst95 = 1.0f / fConst91;
		fConst96 = (fConst95 + -0.618034f) / fConst91 + 1.0f;
		fConst97 = 1.0f / ((fConst95 + 0.618034f) / fConst91 + 1.0f);
		fConst98 = (fConst95 + -1.618034f) / fConst91 + 1.0f;
		fConst99 = (fConst95 + 1.618034f) / fConst91 + 1.0f;
		fConst100 = 1.0f / fConst99;
		fConst101 = std::tan(12566.371f / fConst0);
		fConst102 = effect_faustpower2_f(fConst101);
		fConst103 = 2.0f * (1.0f - 1.0f / fConst102);
		fConst104 = 1.0f / fConst101;
		fConst105 = (fConst104 + -0.618034f) / fConst101 + 1.0f;
		fConst106 = (fConst104 + 0.618034f) / fConst101 + 1.0f;
		fConst107 = 1.0f / fConst106;
		fConst108 = (fConst104 + -1.618034f) / fConst101 + 1.0f;
		fConst109 = (fConst104 + 1.618034f) / fConst101 + 1.0f;
		fConst110 = 1.0f / fConst109;
		fConst111 = 12.566371f / fConst0;
		fConst112 = std::cos(fConst111);
		fConst113 = std::sin(fConst111);
		fConst114 = 1.0f - fConst104;
		fConst115 = 1.0f / (fConst104 + 1.0f);
		fConst116 = 1.0f / (fConst91 * fConst106);
		fConst117 = 1.0f - fConst95;
		fConst118 = 1.0f / (fConst95 + 1.0f);
		fConst119 = 1.0f / (fConst92 * fConst99);
		fConst120 = (fConst95 + -1.618034f) / fConst91 + 1.0f;
		fConst121 = 1.0f / ((fConst95 + 1.618034f) / fConst91 + 1.0f);
		fConst122 = 1.0f / (fConst102 * fConst109);
		fConst123 = 1.0f / (fConst102 * fConst106);
		fConst124 = 0.00028344672f * fConst0;
		iConst125 = std::max<int>(0, iConst4 + 22);
		iConst126 = std::max<int>(0, iConst6 + 22);
		iConst127 = std::max<int>(0, iConst8 + 22);
		iConst128 = std::max<int>(0, iConst10 + 22);
		iConst129 = std::max<int>(0, iConst12 + 22);
		iConst130 = std::max<int>(0, iConst14 + 22);
		iConst131 = std::max<int>(0, iConst16 + 22);
		iConst132 = std::max<int>(0, iConst18 + 22);
		iConst133 = std::min<int>(1024, std::max<int>(0, iConst20 + 22));
		iConst134 = std::min<int>(1024, std::max<int>(0, iConst22 + 22));
		iConst135 = std::min<int>(1024, std::max<int>(0, iConst24 + 22));
		iConst136 = std::min<int>(1024, std::max<int>(0, iConst26 + 22));
	}
	
	virtual void instanceResetUserInterface() {
		fEntry0 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider0 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider1 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider2 = static_cast<FAUSTFLOAT>(0.375f);
		fHslider3 = static_cast<FAUSTFLOAT>(0.6f);
		fHslider4 = static_cast<FAUSTFLOAT>(0.4f);
		fHslider5 = static_cast<FAUSTFLOAT>(3e+03f);
		fHslider6 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider7 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider8 = static_cast<FAUSTFLOAT>(0.8f);
		fHslider9 = static_cast<FAUSTFLOAT>(0.5f);
		fHslider10 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider11 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider12 = static_cast<FAUSTFLOAT>(0.3f);
		fHslider13 = static_cast<FAUSTFLOAT>(0.0f);
		fHslider14 = static_cast<FAUSTFLOAT>(-12.0f);
	}
	
	virtual void instanceClear() {
		for (int l0 = 0; l0 < 2; l0 = l0 + 1) {
			iVec0[l0] = 0;
		}
		for (int l1 = 0; l1 < 2; l1 = l1 + 1) {
			iVec1[l1] = 0;
		}
		for (int l2 = 0; l2 < 2; l2 = l2 + 1) {
			fVec2[l2] = 0.0f;
		}
		for (int l3 = 0; l3 < 2; l3 = l3 + 1) {
			fVec3[l3] = 0.0f;
		}
		for (int l4 = 0; l4 < 2; l4 = l4 + 1) {
			fRec9[l4] = 0.0f;
		}
		IOTA0 = 0;
		for (int l5 = 0; l5 < 2; l5 = l5 + 1) {
			fVec4[l5] = 0.0f;
		}
		for (int l6 = 0; l6 < 2; l6 = l6 + 1) {
			fRec11[l6] = 0.0f;
		}
		for (int l7 = 0; l7 < 3; l7 = l7 + 1) {
			fRec12[l7] = 0.0f;
		}
		for (int l8 = 0; l8 < 4096; l8 = l8 + 1) {
			fVec5[l8] = 0.0f;
		}
		for (int l11 = 0; l11 < 2; l11 = l11 + 1) {
			fRec14[l11] = 0.0f;
		}
		for (int l12 = 0; l12 < 2; l12 = l12 + 1) {
			fRec15[l12] = 0.0f;
		}
		for (int l13 = 0; l13 < 131072; l13 = l13 + 1) {
			fRec10[l13] = 0.0f;
		}
		for (int l14 = 0; l14 < 8192; l14 = l14 + 1) {
			fVec7[l14] = 0.0f;
		}
		for (int l15 = 0; l15 < 2; l15 = l15 + 1) {
			fRec8[l15] = 0.0f;
		}
		for (int l16 = 0; l16 < 2; l16 = l16 + 1) {
			fRec17[l16] = 0.0f;
		}
		for (int l17 = 0; l17 < 8192; l17 = l17 + 1) {
			fVec8[l17] = 0.0f;
		}
		for (int l18 = 0; l18 < 2; l18 = l18 + 1) {
			fRec16[l18] = 0.0f;
		}
		for (int l19 = 0; l19 < 2; l19 = l19 + 1) {
			fRec19[l19] = 0.0f;
		}
		for (int l20 = 0; l20 < 8192; l20 = l20 + 1) {
			fVec9[l20] = 0.0f;
		}
		for (int l21 = 0; l21 < 2; l21 = l21 + 1) {
			fRec18[l21] = 0.0f;
		}
		for (int l22 = 0; l22 < 2; l22 = l22 + 1) {
			fRec21[l22] = 0.0f;
		}
		for (int l23 = 0; l23 < 8192; l23 = l23 + 1) {
			fVec10[l23] = 0.0f;
		}
		for (int l24 = 0; l24 < 2; l24 = l24 + 1) {
			fRec20[l24] = 0.0f;
		}
		for (int l25 = 0; l25 < 2; l25 = l25 + 1) {
			fRec23[l25] = 0.0f;
		}
		for (int l26 = 0; l26 < 8192; l26 = l26 + 1) {
			fVec11[l26] = 0.0f;
		}
		for (int l27 = 0; l27 < 2; l27 = l27 + 1) {
			fRec22[l27] = 0.0f;
		}
		for (int l28 = 0; l28 < 2; l28 = l28 + 1) {
			fRec25[l28] = 0.0f;
		}
		for (int l29 = 0; l29 < 8192; l29 = l29 + 1) {
			fVec12[l29] = 0.0f;
		}
		for (int l30 = 0; l30 < 2; l30 = l30 + 1) {
			fRec24[l30] = 0.0f;
		}
		for (int l31 = 0; l31 < 2; l31 = l31 + 1) {
			fRec27[l31] = 0.0f;
		}
		for (int l32 = 0; l32 < 8192; l32 = l32 + 1) {
			fVec13[l32] = 0.0f;
		}
		for (int l33 = 0; l33 < 2; l33 = l33 + 1) {
			fRec26[l33] = 0.0f;
		}
		for (int l34 = 0; l34 < 2; l34 = l34 + 1) {
			fRec29[l34] = 0.0f;
		}
		for (int l35 = 0; l35 < 8192; l35 = l35 + 1) {
			fVec14[l35] = 0.0f;
		}
		for (int l36 = 0; l36 < 2; l36 = l36 + 1) {
			fRec28[l36] = 0.0f;
		}
		for (int l37 = 0; l37 < 2048; l37 = l37 + 1) {
			fVec15[l37] = 0.0f;
		}
		for (int l38 = 0; l38 < 2; l38 = l38 + 1) {
			fRec6[l38] = 0.0f;
		}
		for (int l39 = 0; l39 < 2048; l39 = l39 + 1) {
			fVec16[l39] = 0.0f;
		}
		for (int l40 = 0; l40 < 2; l40 = l40 + 1) {
			fRec4[l40] = 0.0f;
		}
		for (int l41 = 0; l41 < 2048; l41 = l41 + 1) {
			fVec17[l41] = 0.0f;
		}
		for (int l42 = 0; l42 < 2; l42 = l42 + 1) {
			fRec2[l42] = 0.0f;
		}
		for (int l43 = 0; l43 < 1024; l43 = l43 + 1) {
			fVec18[l43] = 0.0f;
		}
		for (int l44 = 0; l44 < 2; l44 = l44 + 1) {
			fRec0[l44] = 0.0f;
		}
		for (int l45 = 0; l45 < 2; l45 = l45 + 1) {
			fRec41[l45] = 0.0f;
		}
		for (int l46 = 0; l46 < 2; l46 = l46 + 1) {
			fRec40[l46] = 0.0f;
		}
		for (int l47 = 0; l47 < 16384; l47 = l47 + 1) {
			fVec19[l47] = 0.0f;
		}
		for (int l48 = 0; l48 < 2; l48 = l48 + 1) {
			fVec20[l48] = 0.0f;
		}
		for (int l49 = 0; l49 < 2; l49 = l49 + 1) {
			fRec43[l49] = 0.0f;
		}
		for (int l50 = 0; l50 < 3; l50 = l50 + 1) {
			fRec44[l50] = 0.0f;
		}
		for (int l51 = 0; l51 < 4096; l51 = l51 + 1) {
			fVec21[l51] = 0.0f;
		}
		for (int l52 = 0; l52 < 2; l52 = l52 + 1) {
			fRec45[l52] = 0.0f;
		}
		for (int l53 = 0; l53 < 131072; l53 = l53 + 1) {
			fRec42[l53] = 0.0f;
		}
		for (int l54 = 0; l54 < 16384; l54 = l54 + 1) {
			fVec22[l54] = 0.0f;
		}
		for (int l55 = 0; l55 < 4096; l55 = l55 + 1) {
			fVec23[l55] = 0.0f;
		}
		for (int l56 = 0; l56 < 2; l56 = l56 + 1) {
			fRec38[l56] = 0.0f;
		}
		for (int l57 = 0; l57 < 2; l57 = l57 + 1) {
			fRec49[l57] = 0.0f;
		}
		for (int l58 = 0; l58 < 2; l58 = l58 + 1) {
			fRec48[l58] = 0.0f;
		}
		for (int l59 = 0; l59 < 16384; l59 = l59 + 1) {
			fVec24[l59] = 0.0f;
		}
		for (int l60 = 0; l60 < 2048; l60 = l60 + 1) {
			fVec25[l60] = 0.0f;
		}
		for (int l61 = 0; l61 < 2; l61 = l61 + 1) {
			fRec46[l61] = 0.0f;
		}
		for (int l62 = 0; l62 < 2; l62 = l62 + 1) {
			fRec53[l62] = 0.0f;
		}
		for (int l63 = 0; l63 < 2; l63 = l63 + 1) {
			fRec52[l63] = 0.0f;
		}
		for (int l64 = 0; l64 < 16384; l64 = l64 + 1) {
			fVec26[l64] = 0.0f;
		}
		for (int l65 = 0; l65 < 4096; l65 = l65 + 1) {
			fVec27[l65] = 0.0f;
		}
		for (int l66 = 0; l66 < 2; l66 = l66 + 1) {
			fRec50[l66] = 0.0f;
		}
		for (int l67 = 0; l67 < 2; l67 = l67 + 1) {
			fRec57[l67] = 0.0f;
		}
		for (int l68 = 0; l68 < 2; l68 = l68 + 1) {
			fRec56[l68] = 0.0f;
		}
		for (int l69 = 0; l69 < 16384; l69 = l69 + 1) {
			fVec28[l69] = 0.0f;
		}
		for (int l70 = 0; l70 < 2048; l70 = l70 + 1) {
			fVec29[l70] = 0.0f;
		}
		for (int l71 = 0; l71 < 2; l71 = l71 + 1) {
			fRec54[l71] = 0.0f;
		}
		for (int l72 = 0; l72 < 2; l72 = l72 + 1) {
			fRec61[l72] = 0.0f;
		}
		for (int l73 = 0; l73 < 2; l73 = l73 + 1) {
			fRec60[l73] = 0.0f;
		}
		for (int l74 = 0; l74 < 32768; l74 = l74 + 1) {
			fVec30[l74] = 0.0f;
		}
		for (int l75 = 0; l75 < 4096; l75 = l75 + 1) {
			fVec31[l75] = 0.0f;
		}
		for (int l76 = 0; l76 < 2; l76 = l76 + 1) {
			fRec58[l76] = 0.0f;
		}
		for (int l77 = 0; l77 < 2; l77 = l77 + 1) {
			fRec65[l77] = 0.0f;
		}
		for (int l78 = 0; l78 < 2; l78 = l78 + 1) {
			fRec64[l78] = 0.0f;
		}
		for (int l79 = 0; l79 < 16384; l79 = l79 + 1) {
			fVec32[l79] = 0.0f;
		}
		for (int l80 = 0; l80 < 4096; l80 = l80 + 1) {
			fVec33[l80] = 0.0f;
		}
		for (int l81 = 0; l81 < 2; l81 = l81 + 1) {
			fRec62[l81] = 0.0f;
		}
		for (int l82 = 0; l82 < 2; l82 = l82 + 1) {
			fRec69[l82] = 0.0f;
		}
		for (int l83 = 0; l83 < 2; l83 = l83 + 1) {
			fRec68[l83] = 0.0f;
		}
		for (int l84 = 0; l84 < 32768; l84 = l84 + 1) {
			fVec34[l84] = 0.0f;
		}
		for (int l85 = 0; l85 < 4096; l85 = l85 + 1) {
			fVec35[l85] = 0.0f;
		}
		for (int l86 = 0; l86 < 2; l86 = l86 + 1) {
			fRec66[l86] = 0.0f;
		}
		for (int l87 = 0; l87 < 2; l87 = l87 + 1) {
			fRec73[l87] = 0.0f;
		}
		for (int l88 = 0; l88 < 2; l88 = l88 + 1) {
			fRec72[l88] = 0.0f;
		}
		for (int l89 = 0; l89 < 32768; l89 = l89 + 1) {
			fVec36[l89] = 0.0f;
		}
		for (int l90 = 0; l90 < 2048; l90 = l90 + 1) {
			fVec37[l90] = 0.0f;
		}
		for (int l91 = 0; l91 < 2; l91 = l91 + 1) {
			fRec70[l91] = 0.0f;
		}
		for (int l92 = 0; l92 < 3; l92 = l92 + 1) {
			fRec30[l92] = 0.0f;
		}
		for (int l93 = 0; l93 < 3; l93 = l93 + 1) {
			fRec31[l93] = 0.0f;
		}
		for (int l94 = 0; l94 < 3; l94 = l94 + 1) {
			fRec32[l94] = 0.0f;
		}
		for (int l95 = 0; l95 < 3; l95 = l95 + 1) {
			fRec33[l95] = 0.0f;
		}
		for (int l96 = 0; l96 < 3; l96 = l96 + 1) {
			fRec34[l96] = 0.0f;
		}
		for (int l97 = 0; l97 < 3; l97 = l97 + 1) {
			fRec35[l97] = 0.0f;
		}
		for (int l98 = 0; l98 < 3; l98 = l98 + 1) {
			fRec36[l98] = 0.0f;
		}
		for (int l99 = 0; l99 < 3; l99 = l99 + 1) {
			fRec37[l99] = 0.0f;
		}
		for (int l100 = 0; l100 < 1024; l100 = l100 + 1) {
			fVec38[l100] = 0.0f;
		}
		for (int l101 = 0; l101 < 2; l101 = l101 + 1) {
			fRec79[l101] = 0.0f;
		}
		for (int l102 = 0; l102 < 8192; l102 = l102 + 1) {
			fVec39[l102] = 0.0f;
		}
		for (int l103 = 0; l103 < 2; l103 = l103 + 1) {
			fRec78[l103] = 0.0f;
		}
		for (int l104 = 0; l104 < 4096; l104 = l104 + 1) {
			fVec40[l104] = 0.0f;
		}
		for (int l105 = 0; l105 < 2; l105 = l105 + 1) {
			fRec76[l105] = 0.0f;
		}
		for (int l106 = 0; l106 < 4096; l106 = l106 + 1) {
			fVec41[l106] = 0.0f;
		}
		for (int l107 = 0; l107 < 3; l107 = l107 + 1) {
			fRec89[l107] = 0.0f;
		}
		for (int l108 = 0; l108 < 256; l108 = l108 + 1) {
			fVec42[l108] = 0.0f;
		}
		for (int l109 = 0; l109 < 2; l109 = l109 + 1) {
			fRec87[l109] = 0.0f;
		}
		for (int l110 = 0; l110 < 128; l110 = l110 + 1) {
			fVec43[l110] = 0.0f;
		}
		for (int l111 = 0; l111 < 2; l111 = l111 + 1) {
			fRec85[l111] = 0.0f;
		}
		for (int l112 = 0; l112 < 512; l112 = l112 + 1) {
			fVec44[l112] = 0.0f;
		}
		for (int l113 = 0; l113 < 2; l113 = l113 + 1) {
			fRec83[l113] = 0.0f;
		}
		for (int l114 = 0; l114 < 512; l114 = l114 + 1) {
			fVec45[l114] = 0.0f;
		}
		for (int l115 = 0; l115 < 2; l115 = l115 + 1) {
			fRec81[l115] = 0.0f;
		}
		for (int l116 = 0; l116 < 2; l116 = l116 + 1) {
			fRec74[l116] = 0.0f;
		}
		for (int l117 = 0; l117 < 1024; l117 = l117 + 1) {
			fVec46[l117] = 0.0f;
		}
		for (int l118 = 0; l118 < 2; l118 = l118 + 1) {
			fRec93[l118] = 0.0f;
		}
		for (int l119 = 0; l119 < 8192; l119 = l119 + 1) {
			fVec47[l119] = 0.0f;
		}
		for (int l120 = 0; l120 < 2; l120 = l120 + 1) {
			fRec92[l120] = 0.0f;
		}
		for (int l121 = 0; l121 < 2048; l121 = l121 + 1) {
			fVec48[l121] = 0.0f;
		}
		for (int l122 = 0; l122 < 2; l122 = l122 + 1) {
			fRec90[l122] = 0.0f;
		}
		for (int l123 = 0; l123 < 2048; l123 = l123 + 1) {
			fVec49[l123] = 0.0f;
		}
		for (int l124 = 0; l124 < 2; l124 = l124 + 1) {
			fRec75[l124] = 0.0f;
		}
		for (int l125 = 0; l125 < 2; l125 = l125 + 1) {
			fRec105[l125] = 0.0f;
		}
		for (int l126 = 0; l126 < 2; l126 = l126 + 1) {
			fRec107[l126] = 0.0f;
		}
		for (int l127 = 0; l127 < 2; l127 = l127 + 1) {
			fRec111[l127] = 0.0f;
		}
		for (int l128 = 0; l128 < 16384; l128 = l128 + 1) {
			fVec50[l128] = 0.0f;
		}
		for (int l129 = 0; l129 < 2; l129 = l129 + 1) {
			fVec51[l129] = 0.0f;
		}
		for (int l130 = 0; l130 < 2; l130 = l130 + 1) {
			fRec110[l130] = 0.0f;
		}
		for (int l131 = 0; l131 < 2; l131 = l131 + 1) {
			fRec108[l131] = 0.0f;
		}
		for (int l132 = 0; l132 < 2; l132 = l132 + 1) {
			fRec113[l132] = 0.0f;
		}
		for (int l133 = 0; l133 < 16384; l133 = l133 + 1) {
			fVec52[l133] = 0.0f;
		}
		for (int l134 = 0; l134 < 2; l134 = l134 + 1) {
			fVec53[l134] = 0.0f;
		}
		for (int l135 = 0; l135 < 2; l135 = l135 + 1) {
			fRec112[l135] = 0.0f;
		}
		for (int l136 = 0; l136 < 2; l136 = l136 + 1) {
			fRec109[l136] = 0.0f;
		}
		for (int l137 = 0; l137 < 2; l137 = l137 + 1) {
			fRec117[l137] = 0.0f;
		}
		for (int l138 = 0; l138 < 16384; l138 = l138 + 1) {
			fVec54[l138] = 0.0f;
		}
		for (int l139 = 0; l139 < 2; l139 = l139 + 1) {
			fVec55[l139] = 0.0f;
		}
		for (int l140 = 0; l140 < 2; l140 = l140 + 1) {
			fRec116[l140] = 0.0f;
		}
		for (int l141 = 0; l141 < 2; l141 = l141 + 1) {
			fRec114[l141] = 0.0f;
		}
		for (int l142 = 0; l142 < 2; l142 = l142 + 1) {
			fRec119[l142] = 0.0f;
		}
		for (int l143 = 0; l143 < 16384; l143 = l143 + 1) {
			fVec56[l143] = 0.0f;
		}
		for (int l144 = 0; l144 < 2; l144 = l144 + 1) {
			fVec57[l144] = 0.0f;
		}
		for (int l145 = 0; l145 < 2; l145 = l145 + 1) {
			fRec118[l145] = 0.0f;
		}
		for (int l146 = 0; l146 < 2; l146 = l146 + 1) {
			fRec115[l146] = 0.0f;
		}
		for (int l147 = 0; l147 < 2; l147 = l147 + 1) {
			fRec123[l147] = 0.0f;
		}
		for (int l148 = 0; l148 < 16384; l148 = l148 + 1) {
			fVec58[l148] = 0.0f;
		}
		for (int l149 = 0; l149 < 2; l149 = l149 + 1) {
			fVec59[l149] = 0.0f;
		}
		for (int l150 = 0; l150 < 2; l150 = l150 + 1) {
			fRec122[l150] = 0.0f;
		}
		for (int l151 = 0; l151 < 2; l151 = l151 + 1) {
			fRec120[l151] = 0.0f;
		}
		for (int l152 = 0; l152 < 2; l152 = l152 + 1) {
			fRec125[l152] = 0.0f;
		}
		for (int l153 = 0; l153 < 16384; l153 = l153 + 1) {
			fVec60[l153] = 0.0f;
		}
		for (int l154 = 0; l154 < 2; l154 = l154 + 1) {
			fVec61[l154] = 0.0f;
		}
		for (int l155 = 0; l155 < 2; l155 = l155 + 1) {
			fRec124[l155] = 0.0f;
		}
		for (int l156 = 0; l156 < 2; l156 = l156 + 1) {
			fRec121[l156] = 0.0f;
		}
		for (int l157 = 0; l157 < 2; l157 = l157 + 1) {
			fRec129[l157] = 0.0f;
		}
		for (int l158 = 0; l158 < 16384; l158 = l158 + 1) {
			fVec62[l158] = 0.0f;
		}
		for (int l159 = 0; l159 < 2; l159 = l159 + 1) {
			fVec63[l159] = 0.0f;
		}
		for (int l160 = 0; l160 < 2; l160 = l160 + 1) {
			fRec128[l160] = 0.0f;
		}
		for (int l161 = 0; l161 < 2; l161 = l161 + 1) {
			fRec126[l161] = 0.0f;
		}
		for (int l162 = 0; l162 < 2; l162 = l162 + 1) {
			fRec131[l162] = 0.0f;
		}
		for (int l163 = 0; l163 < 16384; l163 = l163 + 1) {
			fVec64[l163] = 0.0f;
		}
		for (int l164 = 0; l164 < 2; l164 = l164 + 1) {
			fVec65[l164] = 0.0f;
		}
		for (int l165 = 0; l165 < 2; l165 = l165 + 1) {
			fRec130[l165] = 0.0f;
		}
		for (int l166 = 0; l166 < 2; l166 = l166 + 1) {
			fRec127[l166] = 0.0f;
		}
		for (int l167 = 0; l167 < 2; l167 = l167 + 1) {
			fRec135[l167] = 0.0f;
		}
		for (int l168 = 0; l168 < 16384; l168 = l168 + 1) {
			fVec66[l168] = 0.0f;
		}
		for (int l169 = 0; l169 < 2; l169 = l169 + 1) {
			fVec67[l169] = 0.0f;
		}
		for (int l170 = 0; l170 < 2; l170 = l170 + 1) {
			fRec134[l170] = 0.0f;
		}
		for (int l171 = 0; l171 < 2; l171 = l171 + 1) {
			fRec132[l171] = 0.0f;
		}
		for (int l172 = 0; l172 < 2; l172 = l172 + 1) {
			fRec137[l172] = 0.0f;
		}
		for (int l173 = 0; l173 < 16384; l173 = l173 + 1) {
			fVec68[l173] = 0.0f;
		}
		for (int l174 = 0; l174 < 2; l174 = l174 + 1) {
			fVec69[l174] = 0.0f;
		}
		for (int l175 = 0; l175 < 2; l175 = l175 + 1) {
			fRec136[l175] = 0.0f;
		}
		for (int l176 = 0; l176 < 2; l176 = l176 + 1) {
			fRec133[l176] = 0.0f;
		}
		for (int l177 = 0; l177 < 1024; l177 = l177 + 1) {
			fVec70[l177] = 0.0f;
		}
		for (int l178 = 0; l178 < 2; l178 = l178 + 1) {
			fRec138[l178] = 0.0f;
		}
		for (int l179 = 0; l179 < 2; l179 = l179 + 1) {
			fRec139[l179] = 0.0f;
		}
		for (int l180 = 0; l180 < 2; l180 = l180 + 1) {
			fVec71[l180] = 0.0f;
		}
		for (int l181 = 0; l181 < 16384; l181 = l181 + 1) {
			fVec72[l181] = 0.0f;
		}
		for (int l182 = 0; l182 < 2; l182 = l182 + 1) {
			fVec73[l182] = 0.0f;
		}
		for (int l183 = 0; l183 < 2; l183 = l183 + 1) {
			fRec106[l183] = 0.0f;
		}
		for (int l184 = 0; l184 < 2; l184 = l184 + 1) {
			fRec143[l184] = 0.0f;
		}
		for (int l185 = 0; l185 < 2; l185 = l185 + 1) {
			fRec145[l185] = 0.0f;
		}
		for (int l186 = 0; l186 < 1024; l186 = l186 + 1) {
			fVec74[l186] = 0.0f;
		}
		for (int l187 = 0; l187 < 16384; l187 = l187 + 1) {
			fVec75[l187] = 0.0f;
		}
		for (int l188 = 0; l188 < 2; l188 = l188 + 1) {
			fVec76[l188] = 0.0f;
		}
		for (int l189 = 0; l189 < 2; l189 = l189 + 1) {
			fRec144[l189] = 0.0f;
		}
		for (int l190 = 0; l190 < 16384; l190 = l190 + 1) {
			fVec77[l190] = 0.0f;
		}
		for (int l191 = 0; l191 < 2; l191 = l191 + 1) {
			fVec78[l191] = 0.0f;
		}
		for (int l192 = 0; l192 < 2; l192 = l192 + 1) {
			fRec142[l192] = 0.0f;
		}
		for (int l193 = 0; l193 < 2; l193 = l193 + 1) {
			fRec140[l193] = 0.0f;
		}
		for (int l194 = 0; l194 < 2; l194 = l194 + 1) {
			fRec147[l194] = 0.0f;
		}
		for (int l195 = 0; l195 < 16384; l195 = l195 + 1) {
			fVec79[l195] = 0.0f;
		}
		for (int l196 = 0; l196 < 2; l196 = l196 + 1) {
			fVec80[l196] = 0.0f;
		}
		for (int l197 = 0; l197 < 2; l197 = l197 + 1) {
			fRec146[l197] = 0.0f;
		}
		for (int l198 = 0; l198 < 2; l198 = l198 + 1) {
			fRec141[l198] = 0.0f;
		}
		for (int l199 = 0; l199 < 2; l199 = l199 + 1) {
			fRec151[l199] = 0.0f;
		}
		for (int l200 = 0; l200 < 16384; l200 = l200 + 1) {
			fVec81[l200] = 0.0f;
		}
		for (int l201 = 0; l201 < 2; l201 = l201 + 1) {
			fVec82[l201] = 0.0f;
		}
		for (int l202 = 0; l202 < 2; l202 = l202 + 1) {
			fRec150[l202] = 0.0f;
		}
		for (int l203 = 0; l203 < 2; l203 = l203 + 1) {
			fRec148[l203] = 0.0f;
		}
		for (int l204 = 0; l204 < 2; l204 = l204 + 1) {
			fRec153[l204] = 0.0f;
		}
		for (int l205 = 0; l205 < 16384; l205 = l205 + 1) {
			fVec83[l205] = 0.0f;
		}
		for (int l206 = 0; l206 < 2; l206 = l206 + 1) {
			fVec84[l206] = 0.0f;
		}
		for (int l207 = 0; l207 < 2; l207 = l207 + 1) {
			fRec152[l207] = 0.0f;
		}
		for (int l208 = 0; l208 < 2; l208 = l208 + 1) {
			fRec149[l208] = 0.0f;
		}
		for (int l209 = 0; l209 < 2; l209 = l209 + 1) {
			fRec157[l209] = 0.0f;
		}
		for (int l210 = 0; l210 < 16384; l210 = l210 + 1) {
			fVec85[l210] = 0.0f;
		}
		for (int l211 = 0; l211 < 2; l211 = l211 + 1) {
			fVec86[l211] = 0.0f;
		}
		for (int l212 = 0; l212 < 2; l212 = l212 + 1) {
			fRec156[l212] = 0.0f;
		}
		for (int l213 = 0; l213 < 2; l213 = l213 + 1) {
			fRec154[l213] = 0.0f;
		}
		for (int l214 = 0; l214 < 2; l214 = l214 + 1) {
			fRec159[l214] = 0.0f;
		}
		for (int l215 = 0; l215 < 16384; l215 = l215 + 1) {
			fVec87[l215] = 0.0f;
		}
		for (int l216 = 0; l216 < 2; l216 = l216 + 1) {
			fVec88[l216] = 0.0f;
		}
		for (int l217 = 0; l217 < 2; l217 = l217 + 1) {
			fRec158[l217] = 0.0f;
		}
		for (int l218 = 0; l218 < 2; l218 = l218 + 1) {
			fRec155[l218] = 0.0f;
		}
		for (int l219 = 0; l219 < 2; l219 = l219 + 1) {
			fRec163[l219] = 0.0f;
		}
		for (int l220 = 0; l220 < 16384; l220 = l220 + 1) {
			fVec89[l220] = 0.0f;
		}
		for (int l221 = 0; l221 < 2; l221 = l221 + 1) {
			fVec90[l221] = 0.0f;
		}
		for (int l222 = 0; l222 < 2; l222 = l222 + 1) {
			fRec162[l222] = 0.0f;
		}
		for (int l223 = 0; l223 < 2; l223 = l223 + 1) {
			fRec160[l223] = 0.0f;
		}
		for (int l224 = 0; l224 < 2; l224 = l224 + 1) {
			fRec165[l224] = 0.0f;
		}
		for (int l225 = 0; l225 < 16384; l225 = l225 + 1) {
			fVec91[l225] = 0.0f;
		}
		for (int l226 = 0; l226 < 2; l226 = l226 + 1) {
			fVec92[l226] = 0.0f;
		}
		for (int l227 = 0; l227 < 2; l227 = l227 + 1) {
			fRec164[l227] = 0.0f;
		}
		for (int l228 = 0; l228 < 2; l228 = l228 + 1) {
			fRec161[l228] = 0.0f;
		}
		for (int l229 = 0; l229 < 2; l229 = l229 + 1) {
			fRec169[l229] = 0.0f;
		}
		for (int l230 = 0; l230 < 16384; l230 = l230 + 1) {
			fVec93[l230] = 0.0f;
		}
		for (int l231 = 0; l231 < 2; l231 = l231 + 1) {
			fVec94[l231] = 0.0f;
		}
		for (int l232 = 0; l232 < 2; l232 = l232 + 1) {
			fRec168[l232] = 0.0f;
		}
		for (int l233 = 0; l233 < 2; l233 = l233 + 1) {
			fRec166[l233] = 0.0f;
		}
		for (int l234 = 0; l234 < 2; l234 = l234 + 1) {
			fRec171[l234] = 0.0f;
		}
		for (int l235 = 0; l235 < 16384; l235 = l235 + 1) {
			fVec95[l235] = 0.0f;
		}
		for (int l236 = 0; l236 < 2; l236 = l236 + 1) {
			fVec96[l236] = 0.0f;
		}
		for (int l237 = 0; l237 < 2; l237 = l237 + 1) {
			fRec170[l237] = 0.0f;
		}
		for (int l238 = 0; l238 < 2; l238 = l238 + 1) {
			fRec167[l238] = 0.0f;
		}
		for (int l239 = 0; l239 < 16384; l239 = l239 + 1) {
			fVec97[l239] = 0.0f;
		}
		for (int l240 = 0; l240 < 16384; l240 = l240 + 1) {
			fVec98[l240] = 0.0f;
		}
		for (int l241 = 0; l241 < 2; l241 = l241 + 1) {
			fVec99[l241] = 0.0f;
		}
		for (int l242 = 0; l242 < 2; l242 = l242 + 1) {
			fRec104[l242] = 0.0f;
		}
		for (int l243 = 0; l243 < 2; l243 = l243 + 1) {
			fRec103[l243] = 0.0f;
		}
		for (int l244 = 0; l244 < 3; l244 = l244 + 1) {
			fRec102[l244] = 0.0f;
		}
		for (int l245 = 0; l245 < 3; l245 = l245 + 1) {
			fRec101[l245] = 0.0f;
		}
		for (int l246 = 0; l246 < 2; l246 = l246 + 1) {
			fVec100[l246] = 0.0f;
		}
		for (int l247 = 0; l247 < 2; l247 = l247 + 1) {
			fRec100[l247] = 0.0f;
		}
		for (int l248 = 0; l248 < 3; l248 = l248 + 1) {
			fRec99[l248] = 0.0f;
		}
		for (int l249 = 0; l249 < 3; l249 = l249 + 1) {
			fRec98[l249] = 0.0f;
		}
		for (int l250 = 0; l250 < 2; l250 = l250 + 1) {
			fRec174[l250] = 0.0f;
		}
		for (int l251 = 0; l251 < 3; l251 = l251 + 1) {
			fRec173[l251] = 0.0f;
		}
		for (int l252 = 0; l252 < 3; l252 = l252 + 1) {
			fRec172[l252] = 0.0f;
		}
		for (int l253 = 0; l253 < 2; l253 = l253 + 1) {
			fRec178[l253] = 0.0f;
		}
		for (int l254 = 0; l254 < 3; l254 = l254 + 1) {
			fRec177[l254] = 0.0f;
		}
		for (int l255 = 0; l255 < 3; l255 = l255 + 1) {
			fRec176[l255] = 0.0f;
		}
		for (int l256 = 0; l256 < 3; l256 = l256 + 1) {
			fRec175[l256] = 0.0f;
		}
		for (int l257 = 0; l257 < 1024; l257 = l257 + 1) {
			fVec101[l257] = 0.0f;
		}
		for (int l258 = 0; l258 < 2; l258 = l258 + 1) {
			fRec97[l258] = 0.0f;
		}
		for (int l259 = 0; l259 < 2; l259 = l259 + 1) {
			fRec190[l259] = 0.0f;
		}
		for (int l260 = 0; l260 < 16384; l260 = l260 + 1) {
			fVec102[l260] = 0.0f;
		}
		for (int l261 = 0; l261 < 16384; l261 = l261 + 1) {
			fVec103[l261] = 0.0f;
		}
		for (int l262 = 0; l262 < 2; l262 = l262 + 1) {
			fVec104[l262] = 0.0f;
		}
		for (int l263 = 0; l263 < 2; l263 = l263 + 1) {
			fRec189[l263] = 0.0f;
		}
		for (int l264 = 0; l264 < 2; l264 = l264 + 1) {
			fRec188[l264] = 0.0f;
		}
		for (int l265 = 0; l265 < 3; l265 = l265 + 1) {
			fRec187[l265] = 0.0f;
		}
		for (int l266 = 0; l266 < 3; l266 = l266 + 1) {
			fRec186[l266] = 0.0f;
		}
		for (int l267 = 0; l267 < 2; l267 = l267 + 1) {
			fVec105[l267] = 0.0f;
		}
		for (int l268 = 0; l268 < 2; l268 = l268 + 1) {
			fRec185[l268] = 0.0f;
		}
		for (int l269 = 0; l269 < 3; l269 = l269 + 1) {
			fRec184[l269] = 0.0f;
		}
		for (int l270 = 0; l270 < 3; l270 = l270 + 1) {
			fRec183[l270] = 0.0f;
		}
		for (int l271 = 0; l271 < 2; l271 = l271 + 1) {
			fRec193[l271] = 0.0f;
		}
		for (int l272 = 0; l272 < 3; l272 = l272 + 1) {
			fRec192[l272] = 0.0f;
		}
		for (int l273 = 0; l273 < 3; l273 = l273 + 1) {
			fRec191[l273] = 0.0f;
		}
		for (int l274 = 0; l274 < 2; l274 = l274 + 1) {
			fRec197[l274] = 0.0f;
		}
		for (int l275 = 0; l275 < 3; l275 = l275 + 1) {
			fRec196[l275] = 0.0f;
		}
		for (int l276 = 0; l276 < 3; l276 = l276 + 1) {
			fRec195[l276] = 0.0f;
		}
		for (int l277 = 0; l277 < 3; l277 = l277 + 1) {
			fRec194[l277] = 0.0f;
		}
		for (int l278 = 0; l278 < 1024; l278 = l278 + 1) {
			fVec106[l278] = 0.0f;
		}
		for (int l279 = 0; l279 < 2; l279 = l279 + 1) {
			fRec182[l279] = 0.0f;
		}
		for (int l280 = 0; l280 < 16384; l280 = l280 + 1) {
			fVec107[l280] = 0.0f;
		}
		for (int l281 = 0; l281 < 2; l281 = l281 + 1) {
			fVec108[l281] = 0.0f;
		}
		for (int l282 = 0; l282 < 2; l282 = l282 + 1) {
			fRec181[l282] = 0.0f;
		}
		for (int l283 = 0; l283 < 2; l283 = l283 + 1) {
			fRec179[l283] = 0.0f;
		}
		for (int l284 = 0; l284 < 2; l284 = l284 + 1) {
			fRec199[l284] = 0.0f;
		}
		for (int l285 = 0; l285 < 16384; l285 = l285 + 1) {
			fVec109[l285] = 0.0f;
		}
		for (int l286 = 0; l286 < 2; l286 = l286 + 1) {
			fVec110[l286] = 0.0f;
		}
		for (int l287 = 0; l287 < 2; l287 = l287 + 1) {
			fRec198[l287] = 0.0f;
		}
		for (int l288 = 0; l288 < 2; l288 = l288 + 1) {
			fRec180[l288] = 0.0f;
		}
		for (int l289 = 0; l289 < 16384; l289 = l289 + 1) {
			fVec111[l289] = 0.0f;
		}
		for (int l290 = 0; l290 < 2; l290 = l290 + 1) {
			fVec112[l290] = 0.0f;
		}
		for (int l291 = 0; l291 < 2; l291 = l291 + 1) {
			fRec202[l291] = 0.0f;
		}
		for (int l292 = 0; l292 < 2; l292 = l292 + 1) {
			fRec200[l292] = 0.0f;
		}
		for (int l293 = 0; l293 < 16384; l293 = l293 + 1) {
			fVec113[l293] = 0.0f;
		}
		for (int l294 = 0; l294 < 2; l294 = l294 + 1) {
			fVec114[l294] = 0.0f;
		}
		for (int l295 = 0; l295 < 2; l295 = l295 + 1) {
			fRec203[l295] = 0.0f;
		}
		for (int l296 = 0; l296 < 2; l296 = l296 + 1) {
			fRec201[l296] = 0.0f;
		}
		for (int l297 = 0; l297 < 16384; l297 = l297 + 1) {
			fVec115[l297] = 0.0f;
		}
		for (int l298 = 0; l298 < 2; l298 = l298 + 1) {
			fVec116[l298] = 0.0f;
		}
		for (int l299 = 0; l299 < 2; l299 = l299 + 1) {
			fRec206[l299] = 0.0f;
		}
		for (int l300 = 0; l300 < 2; l300 = l300 + 1) {
			fRec204[l300] = 0.0f;
		}
		for (int l301 = 0; l301 < 2; l301 = l301 + 1) {
			fRec208[l301] = 0.0f;
		}
		for (int l302 = 0; l302 < 16384; l302 = l302 + 1) {
			fVec117[l302] = 0.0f;
		}
		for (int l303 = 0; l303 < 2; l303 = l303 + 1) {
			fVec118[l303] = 0.0f;
		}
		for (int l304 = 0; l304 < 2; l304 = l304 + 1) {
			fRec207[l304] = 0.0f;
		}
		for (int l305 = 0; l305 < 2; l305 = l305 + 1) {
			fRec205[l305] = 0.0f;
		}
		for (int l306 = 0; l306 < 2; l306 = l306 + 1) {
			fRec212[l306] = 0.0f;
		}
		for (int l307 = 0; l307 < 16384; l307 = l307 + 1) {
			fVec119[l307] = 0.0f;
		}
		for (int l308 = 0; l308 < 2; l308 = l308 + 1) {
			fVec120[l308] = 0.0f;
		}
		for (int l309 = 0; l309 < 2; l309 = l309 + 1) {
			fRec211[l309] = 0.0f;
		}
		for (int l310 = 0; l310 < 2; l310 = l310 + 1) {
			fRec209[l310] = 0.0f;
		}
		for (int l311 = 0; l311 < 16384; l311 = l311 + 1) {
			fVec121[l311] = 0.0f;
		}
		for (int l312 = 0; l312 < 2; l312 = l312 + 1) {
			fVec122[l312] = 0.0f;
		}
		for (int l313 = 0; l313 < 2; l313 = l313 + 1) {
			fRec213[l313] = 0.0f;
		}
		for (int l314 = 0; l314 < 2; l314 = l314 + 1) {
			fRec210[l314] = 0.0f;
		}
		for (int l315 = 0; l315 < 2; l315 = l315 + 1) {
			fRec95[l315] = 0.0f;
		}
		for (int l316 = 0; l316 < 2; l316 = l316 + 1) {
			fRec96[l316] = 0.0f;
		}
		for (int l317 = 0; l317 < 2; l317 = l317 + 1) {
			fVec123[l317] = 0.0f;
		}
		for (int l318 = 0; l318 < 2; l318 = l318 + 1) {
			fRec217[l318] = 0.0f;
		}
		for (int l319 = 0; l319 < 2; l319 = l319 + 1) {
			fRec218[l319] = 0.0f;
		}
		for (int l320 = 0; l320 < 131072; l320 = l320 + 1) {
			fVec124[l320] = 0.0f;
		}
		for (int l321 = 0; l321 < 2; l321 = l321 + 1) {
			fRec219[l321] = 0.0f;
		}
		for (int l322 = 0; l322 < 2; l322 = l322 + 1) {
			fRec220[l322] = 0.0f;
		}
		for (int l323 = 0; l323 < 2; l323 = l323 + 1) {
			fRec221[l323] = 0.0f;
		}
		for (int l324 = 0; l324 < 2; l324 = l324 + 1) {
			fRec222[l324] = 0.0f;
		}
		for (int l325 = 0; l325 < 131072; l325 = l325 + 1) {
			fVec125[l325] = 0.0f;
		}
		for (int l326 = 0; l326 < 2; l326 = l326 + 1) {
			fRec235[l326] = 0.0f;
		}
		for (int l327 = 0; l327 < 16384; l327 = l327 + 1) {
			fVec126[l327] = 0.0f;
		}
		for (int l328 = 0; l328 < 2; l328 = l328 + 1) {
			fVec127[l328] = 0.0f;
		}
		for (int l329 = 0; l329 < 2; l329 = l329 + 1) {
			fRec234[l329] = 0.0f;
		}
		for (int l330 = 0; l330 < 2; l330 = l330 + 1) {
			fRec232[l330] = 0.0f;
		}
		for (int l331 = 0; l331 < 2; l331 = l331 + 1) {
			fRec237[l331] = 0.0f;
		}
		for (int l332 = 0; l332 < 16384; l332 = l332 + 1) {
			fVec128[l332] = 0.0f;
		}
		for (int l333 = 0; l333 < 2; l333 = l333 + 1) {
			fVec129[l333] = 0.0f;
		}
		for (int l334 = 0; l334 < 2; l334 = l334 + 1) {
			fRec236[l334] = 0.0f;
		}
		for (int l335 = 0; l335 < 2; l335 = l335 + 1) {
			fRec233[l335] = 0.0f;
		}
		for (int l336 = 0; l336 < 16384; l336 = l336 + 1) {
			fVec130[l336] = 0.0f;
		}
		for (int l337 = 0; l337 < 2; l337 = l337 + 1) {
			fRec238[l337] = 0.0f;
		}
		for (int l338 = 0; l338 < 2; l338 = l338 + 1) {
			fVec131[l338] = 0.0f;
		}
		for (int l339 = 0; l339 < 2; l339 = l339 + 1) {
			fRec231[l339] = 0.0f;
		}
		for (int l340 = 0; l340 < 2; l340 = l340 + 1) {
			fRec229[l340] = 0.0f;
		}
		for (int l341 = 0; l341 < 2; l341 = l341 + 1) {
			fRec240[l341] = 0.0f;
		}
		for (int l342 = 0; l342 < 16384; l342 = l342 + 1) {
			fVec132[l342] = 0.0f;
		}
		for (int l343 = 0; l343 < 2; l343 = l343 + 1) {
			fVec133[l343] = 0.0f;
		}
		for (int l344 = 0; l344 < 2; l344 = l344 + 1) {
			fRec239[l344] = 0.0f;
		}
		for (int l345 = 0; l345 < 2; l345 = l345 + 1) {
			fRec230[l345] = 0.0f;
		}
		for (int l346 = 0; l346 < 16384; l346 = l346 + 1) {
			fVec134[l346] = 0.0f;
		}
		for (int l347 = 0; l347 < 2; l347 = l347 + 1) {
			fRec241[l347] = 0.0f;
		}
		for (int l348 = 0; l348 < 2; l348 = l348 + 1) {
			fVec135[l348] = 0.0f;
		}
		for (int l349 = 0; l349 < 2; l349 = l349 + 1) {
			fRec228[l349] = 0.0f;
		}
		for (int l350 = 0; l350 < 2; l350 = l350 + 1) {
			fRec226[l350] = 0.0f;
		}
		for (int l351 = 0; l351 < 2; l351 = l351 + 1) {
			fRec243[l351] = 0.0f;
		}
		for (int l352 = 0; l352 < 16384; l352 = l352 + 1) {
			fVec136[l352] = 0.0f;
		}
		for (int l353 = 0; l353 < 2; l353 = l353 + 1) {
			fVec137[l353] = 0.0f;
		}
		for (int l354 = 0; l354 < 2; l354 = l354 + 1) {
			fRec242[l354] = 0.0f;
		}
		for (int l355 = 0; l355 < 2; l355 = l355 + 1) {
			fRec227[l355] = 0.0f;
		}
		for (int l356 = 0; l356 < 16384; l356 = l356 + 1) {
			fVec138[l356] = 0.0f;
		}
		for (int l357 = 0; l357 < 2; l357 = l357 + 1) {
			fVec139[l357] = 0.0f;
		}
		for (int l358 = 0; l358 < 2; l358 = l358 + 1) {
			fRec225[l358] = 0.0f;
		}
		for (int l359 = 0; l359 < 2; l359 = l359 + 1) {
			fRec223[l359] = 0.0f;
		}
		for (int l360 = 0; l360 < 2; l360 = l360 + 1) {
			fRec245[l360] = 0.0f;
		}
		for (int l361 = 0; l361 < 16384; l361 = l361 + 1) {
			fVec140[l361] = 0.0f;
		}
		for (int l362 = 0; l362 < 2; l362 = l362 + 1) {
			fVec141[l362] = 0.0f;
		}
		for (int l363 = 0; l363 < 2; l363 = l363 + 1) {
			fRec244[l363] = 0.0f;
		}
		for (int l364 = 0; l364 < 2; l364 = l364 + 1) {
			fRec224[l364] = 0.0f;
		}
		for (int l365 = 0; l365 < 2; l365 = l365 + 1) {
			fRec258[l365] = 0.0f;
		}
		for (int l366 = 0; l366 < 16384; l366 = l366 + 1) {
			fVec142[l366] = 0.0f;
		}
		for (int l367 = 0; l367 < 2; l367 = l367 + 1) {
			fVec143[l367] = 0.0f;
		}
		for (int l368 = 0; l368 < 2; l368 = l368 + 1) {
			fRec257[l368] = 0.0f;
		}
		for (int l369 = 0; l369 < 2; l369 = l369 + 1) {
			fRec255[l369] = 0.0f;
		}
		for (int l370 = 0; l370 < 2; l370 = l370 + 1) {
			fRec260[l370] = 0.0f;
		}
		for (int l371 = 0; l371 < 16384; l371 = l371 + 1) {
			fVec144[l371] = 0.0f;
		}
		for (int l372 = 0; l372 < 2; l372 = l372 + 1) {
			fVec145[l372] = 0.0f;
		}
		for (int l373 = 0; l373 < 2; l373 = l373 + 1) {
			fRec259[l373] = 0.0f;
		}
		for (int l374 = 0; l374 < 2; l374 = l374 + 1) {
			fRec256[l374] = 0.0f;
		}
		for (int l375 = 0; l375 < 16384; l375 = l375 + 1) {
			fVec146[l375] = 0.0f;
		}
		for (int l376 = 0; l376 < 2; l376 = l376 + 1) {
			fVec147[l376] = 0.0f;
		}
		for (int l377 = 0; l377 < 2; l377 = l377 + 1) {
			fRec254[l377] = 0.0f;
		}
		for (int l378 = 0; l378 < 2; l378 = l378 + 1) {
			fRec252[l378] = 0.0f;
		}
		for (int l379 = 0; l379 < 2; l379 = l379 + 1) {
			fRec262[l379] = 0.0f;
		}
		for (int l380 = 0; l380 < 16384; l380 = l380 + 1) {
			fVec148[l380] = 0.0f;
		}
		for (int l381 = 0; l381 < 2; l381 = l381 + 1) {
			fVec149[l381] = 0.0f;
		}
		for (int l382 = 0; l382 < 2; l382 = l382 + 1) {
			fRec261[l382] = 0.0f;
		}
		for (int l383 = 0; l383 < 2; l383 = l383 + 1) {
			fRec253[l383] = 0.0f;
		}
		for (int l384 = 0; l384 < 16384; l384 = l384 + 1) {
			fVec150[l384] = 0.0f;
		}
		for (int l385 = 0; l385 < 2; l385 = l385 + 1) {
			fRec263[l385] = 0.0f;
		}
		for (int l386 = 0; l386 < 2; l386 = l386 + 1) {
			fVec151[l386] = 0.0f;
		}
		for (int l387 = 0; l387 < 2; l387 = l387 + 1) {
			fRec251[l387] = 0.0f;
		}
		for (int l388 = 0; l388 < 2; l388 = l388 + 1) {
			fRec249[l388] = 0.0f;
		}
		for (int l389 = 0; l389 < 2; l389 = l389 + 1) {
			fRec265[l389] = 0.0f;
		}
		for (int l390 = 0; l390 < 16384; l390 = l390 + 1) {
			fVec152[l390] = 0.0f;
		}
		for (int l391 = 0; l391 < 2; l391 = l391 + 1) {
			fVec153[l391] = 0.0f;
		}
		for (int l392 = 0; l392 < 2; l392 = l392 + 1) {
			fRec264[l392] = 0.0f;
		}
		for (int l393 = 0; l393 < 2; l393 = l393 + 1) {
			fRec250[l393] = 0.0f;
		}
		for (int l394 = 0; l394 < 16384; l394 = l394 + 1) {
			fVec154[l394] = 0.0f;
		}
		for (int l395 = 0; l395 < 2; l395 = l395 + 1) {
			fRec266[l395] = 0.0f;
		}
		for (int l396 = 0; l396 < 2; l396 = l396 + 1) {
			fVec155[l396] = 0.0f;
		}
		for (int l397 = 0; l397 < 2; l397 = l397 + 1) {
			fRec248[l397] = 0.0f;
		}
		for (int l398 = 0; l398 < 2; l398 = l398 + 1) {
			fRec246[l398] = 0.0f;
		}
		for (int l399 = 0; l399 < 2; l399 = l399 + 1) {
			fRec268[l399] = 0.0f;
		}
		for (int l400 = 0; l400 < 16384; l400 = l400 + 1) {
			fVec156[l400] = 0.0f;
		}
		for (int l401 = 0; l401 < 2; l401 = l401 + 1) {
			fVec157[l401] = 0.0f;
		}
		for (int l402 = 0; l402 < 2; l402 = l402 + 1) {
			fRec267[l402] = 0.0f;
		}
		for (int l403 = 0; l403 < 2; l403 = l403 + 1) {
			fRec247[l403] = 0.0f;
		}
		for (int l404 = 0; l404 < 2; l404 = l404 + 1) {
			fRec281[l404] = 0.0f;
		}
		for (int l405 = 0; l405 < 16384; l405 = l405 + 1) {
			fVec158[l405] = 0.0f;
		}
		for (int l406 = 0; l406 < 2; l406 = l406 + 1) {
			fVec159[l406] = 0.0f;
		}
		for (int l407 = 0; l407 < 2; l407 = l407 + 1) {
			fRec280[l407] = 0.0f;
		}
		for (int l408 = 0; l408 < 2; l408 = l408 + 1) {
			fRec278[l408] = 0.0f;
		}
		for (int l409 = 0; l409 < 2; l409 = l409 + 1) {
			fRec283[l409] = 0.0f;
		}
		for (int l410 = 0; l410 < 16384; l410 = l410 + 1) {
			fVec160[l410] = 0.0f;
		}
		for (int l411 = 0; l411 < 2; l411 = l411 + 1) {
			fVec161[l411] = 0.0f;
		}
		for (int l412 = 0; l412 < 2; l412 = l412 + 1) {
			fRec282[l412] = 0.0f;
		}
		for (int l413 = 0; l413 < 2; l413 = l413 + 1) {
			fRec279[l413] = 0.0f;
		}
		for (int l414 = 0; l414 < 16384; l414 = l414 + 1) {
			fVec162[l414] = 0.0f;
		}
		for (int l415 = 0; l415 < 2; l415 = l415 + 1) {
			fRec284[l415] = 0.0f;
		}
		for (int l416 = 0; l416 < 2; l416 = l416 + 1) {
			fVec163[l416] = 0.0f;
		}
		for (int l417 = 0; l417 < 2; l417 = l417 + 1) {
			fRec277[l417] = 0.0f;
		}
		for (int l418 = 0; l418 < 2; l418 = l418 + 1) {
			fRec275[l418] = 0.0f;
		}
		for (int l419 = 0; l419 < 2; l419 = l419 + 1) {
			fRec286[l419] = 0.0f;
		}
		for (int l420 = 0; l420 < 16384; l420 = l420 + 1) {
			fVec164[l420] = 0.0f;
		}
		for (int l421 = 0; l421 < 2; l421 = l421 + 1) {
			fVec165[l421] = 0.0f;
		}
		for (int l422 = 0; l422 < 2; l422 = l422 + 1) {
			fRec285[l422] = 0.0f;
		}
		for (int l423 = 0; l423 < 2; l423 = l423 + 1) {
			fRec276[l423] = 0.0f;
		}
		for (int l424 = 0; l424 < 16384; l424 = l424 + 1) {
			fVec166[l424] = 0.0f;
		}
		for (int l425 = 0; l425 < 2; l425 = l425 + 1) {
			fRec287[l425] = 0.0f;
		}
		for (int l426 = 0; l426 < 2; l426 = l426 + 1) {
			fVec167[l426] = 0.0f;
		}
		for (int l427 = 0; l427 < 2; l427 = l427 + 1) {
			fRec274[l427] = 0.0f;
		}
		for (int l428 = 0; l428 < 2; l428 = l428 + 1) {
			fRec272[l428] = 0.0f;
		}
		for (int l429 = 0; l429 < 2; l429 = l429 + 1) {
			fRec289[l429] = 0.0f;
		}
		for (int l430 = 0; l430 < 16384; l430 = l430 + 1) {
			fVec168[l430] = 0.0f;
		}
		for (int l431 = 0; l431 < 2; l431 = l431 + 1) {
			fVec169[l431] = 0.0f;
		}
		for (int l432 = 0; l432 < 2; l432 = l432 + 1) {
			fRec288[l432] = 0.0f;
		}
		for (int l433 = 0; l433 < 2; l433 = l433 + 1) {
			fRec273[l433] = 0.0f;
		}
		for (int l434 = 0; l434 < 16384; l434 = l434 + 1) {
			fVec170[l434] = 0.0f;
		}
		for (int l435 = 0; l435 < 2; l435 = l435 + 1) {
			fRec290[l435] = 0.0f;
		}
		for (int l436 = 0; l436 < 2; l436 = l436 + 1) {
			fVec171[l436] = 0.0f;
		}
		for (int l437 = 0; l437 < 2; l437 = l437 + 1) {
			fRec271[l437] = 0.0f;
		}
		for (int l438 = 0; l438 < 2; l438 = l438 + 1) {
			fRec269[l438] = 0.0f;
		}
		for (int l439 = 0; l439 < 2; l439 = l439 + 1) {
			fRec292[l439] = 0.0f;
		}
		for (int l440 = 0; l440 < 16384; l440 = l440 + 1) {
			fVec172[l440] = 0.0f;
		}
		for (int l441 = 0; l441 < 2; l441 = l441 + 1) {
			fVec173[l441] = 0.0f;
		}
		for (int l442 = 0; l442 < 2; l442 = l442 + 1) {
			fRec291[l442] = 0.0f;
		}
		for (int l443 = 0; l443 < 2; l443 = l443 + 1) {
			fRec270[l443] = 0.0f;
		}
		for (int l444 = 0; l444 < 2; l444 = l444 + 1) {
			fRec216[l444] = 0.0f;
		}
		for (int l445 = 0; l445 < 1024; l445 = l445 + 1) {
			fRec214[l445] = 0.0f;
		}
		for (int l446 = 0; l446 < 2; l446 = l446 + 1) {
			fRec293[l446] = 0.0f;
		}
		for (int l447 = 0; l447 < 1024; l447 = l447 + 1) {
			fRec215[l447] = 0.0f;
		}
		for (int l448 = 0; l448 < 2; l448 = l448 + 1) {
			fRec303[l448] = 0.0f;
		}
		for (int l449 = 0; l449 < 8192; l449 = l449 + 1) {
			fVec174[l449] = 0.0f;
		}
		for (int l450 = 0; l450 < 2; l450 = l450 + 1) {
			fRec302[l450] = 0.0f;
		}
		for (int l451 = 0; l451 < 2; l451 = l451 + 1) {
			fRec305[l451] = 0.0f;
		}
		for (int l452 = 0; l452 < 8192; l452 = l452 + 1) {
			fVec175[l452] = 0.0f;
		}
		for (int l453 = 0; l453 < 2; l453 = l453 + 1) {
			fRec304[l453] = 0.0f;
		}
		for (int l454 = 0; l454 < 2; l454 = l454 + 1) {
			fRec307[l454] = 0.0f;
		}
		for (int l455 = 0; l455 < 8192; l455 = l455 + 1) {
			fVec176[l455] = 0.0f;
		}
		for (int l456 = 0; l456 < 2; l456 = l456 + 1) {
			fRec306[l456] = 0.0f;
		}
		for (int l457 = 0; l457 < 2; l457 = l457 + 1) {
			fRec309[l457] = 0.0f;
		}
		for (int l458 = 0; l458 < 8192; l458 = l458 + 1) {
			fVec177[l458] = 0.0f;
		}
		for (int l459 = 0; l459 < 2; l459 = l459 + 1) {
			fRec308[l459] = 0.0f;
		}
		for (int l460 = 0; l460 < 2; l460 = l460 + 1) {
			fRec311[l460] = 0.0f;
		}
		for (int l461 = 0; l461 < 8192; l461 = l461 + 1) {
			fVec178[l461] = 0.0f;
		}
		for (int l462 = 0; l462 < 2; l462 = l462 + 1) {
			fRec310[l462] = 0.0f;
		}
		for (int l463 = 0; l463 < 2; l463 = l463 + 1) {
			fRec313[l463] = 0.0f;
		}
		for (int l464 = 0; l464 < 8192; l464 = l464 + 1) {
			fVec179[l464] = 0.0f;
		}
		for (int l465 = 0; l465 < 2; l465 = l465 + 1) {
			fRec312[l465] = 0.0f;
		}
		for (int l466 = 0; l466 < 2; l466 = l466 + 1) {
			fRec315[l466] = 0.0f;
		}
		for (int l467 = 0; l467 < 8192; l467 = l467 + 1) {
			fVec180[l467] = 0.0f;
		}
		for (int l468 = 0; l468 < 2; l468 = l468 + 1) {
			fRec314[l468] = 0.0f;
		}
		for (int l469 = 0; l469 < 2; l469 = l469 + 1) {
			fRec317[l469] = 0.0f;
		}
		for (int l470 = 0; l470 < 8192; l470 = l470 + 1) {
			fVec181[l470] = 0.0f;
		}
		for (int l471 = 0; l471 < 2; l471 = l471 + 1) {
			fRec316[l471] = 0.0f;
		}
		for (int l472 = 0; l472 < 2048; l472 = l472 + 1) {
			fVec182[l472] = 0.0f;
		}
		for (int l473 = 0; l473 < 2; l473 = l473 + 1) {
			fRec300[l473] = 0.0f;
		}
		for (int l474 = 0; l474 < 2048; l474 = l474 + 1) {
			fVec183[l474] = 0.0f;
		}
		for (int l475 = 0; l475 < 2; l475 = l475 + 1) {
			fRec298[l475] = 0.0f;
		}
		for (int l476 = 0; l476 < 2048; l476 = l476 + 1) {
			fVec184[l476] = 0.0f;
		}
		for (int l477 = 0; l477 < 2; l477 = l477 + 1) {
			fRec296[l477] = 0.0f;
		}
		for (int l478 = 0; l478 < 1024; l478 = l478 + 1) {
			fVec185[l478] = 0.0f;
		}
		for (int l479 = 0; l479 < 2; l479 = l479 + 1) {
			fRec294[l479] = 0.0f;
		}
	}
	
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}
	
	virtual effect* clone() {
		return new effect(*this);
	}
	
	virtual int getSampleRate() {
		return fSampleRate;
	}
	
	virtual void buildUserInterface(UI* ui_interface) {
		ui_interface->openVerticalBox("effect");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("FX");
		ui_interface->declare(0, "0", "");
		ui_interface->openHorizontalBox("Exciter");
		ui_interface->declare(&fHslider5, "0", "");
		ui_interface->declare(&fHslider5, "scale", "log");
		ui_interface->declare(&fHslider5, "style", "knob");
		ui_interface->addHorizontalSlider("Freq", &fHslider5, FAUSTFLOAT(3e+03f), FAUSTFLOAT(5e+02f), FAUSTFLOAT(1.2e+04f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider6, "1", "");
		ui_interface->declare(&fHslider6, "style", "knob");
		ui_interface->addHorizontalSlider("Drive", &fHslider6, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider7, "2", "");
		ui_interface->declare(&fHslider7, "style", "knob");
		ui_interface->addHorizontalSlider("Mix", &fHslider7, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("Chorus");
		ui_interface->declare(&fHslider8, "0", "");
		ui_interface->declare(&fHslider8, "style", "knob");
		ui_interface->addHorizontalSlider("Rate", &fHslider8, FAUSTFLOAT(0.8f), FAUSTFLOAT(0.1f), FAUSTFLOAT(4.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider9, "1", "");
		ui_interface->declare(&fHslider9, "style", "knob");
		ui_interface->addHorizontalSlider("Depth", &fHslider9, FAUSTFLOAT(0.5f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider10, "2", "");
		ui_interface->declare(&fHslider10, "style", "knob");
		ui_interface->addHorizontalSlider("Wet", &fHslider10, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("Delay");
		ui_interface->declare(&fHslider2, "0", "");
		ui_interface->declare(&fHslider2, "style", "knob");
		ui_interface->addHorizontalSlider("Time", &fHslider2, FAUSTFLOAT(0.375f), FAUSTFLOAT(0.01f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.001f));
		ui_interface->declare(&fHslider4, "1", "");
		ui_interface->declare(&fHslider4, "style", "knob");
		ui_interface->addHorizontalSlider("Fdbk", &fHslider4, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.85f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider3, "2", "");
		ui_interface->declare(&fHslider3, "style", "knob");
		ui_interface->addHorizontalSlider("Tone", &fHslider3, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider11, "3", "");
		ui_interface->declare(&fHslider11, "style", "knob");
		ui_interface->addHorizontalSlider("Wet", &fHslider11, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->declare(0, "3", "");
		ui_interface->openHorizontalBox("Reverb");
		ui_interface->declare(&fEntry0, "0", "");
		ui_interface->declare(&fEntry0, "style", "menu{'Freeverb':0;'Zita':1;'Dattorro':2;'JPverb':3;'Greyhole':4}");
		ui_interface->addNumEntry("Type", &fEntry0, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(4.0f), FAUSTFLOAT(1.0f));
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "style", "knob");
		ui_interface->addHorizontalSlider("Size", &fHslider1, FAUSTFLOAT(0.6f), FAUSTFLOAT(0.1f), FAUSTFLOAT(0.95f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider0, "2", "");
		ui_interface->declare(&fHslider0, "style", "knob");
		ui_interface->addHorizontalSlider("Damp", &fHslider0, FAUSTFLOAT(0.4f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider12, "3", "");
		ui_interface->declare(&fHslider12, "style", "knob");
		ui_interface->addHorizontalSlider("Mod", &fHslider12, FAUSTFLOAT(0.3f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->declare(&fHslider13, "4", "");
		ui_interface->declare(&fHslider13, "style", "knob");
		ui_interface->addHorizontalSlider("Wet", &fHslider13, FAUSTFLOAT(0.0f), FAUSTFLOAT(0.0f), FAUSTFLOAT(1.0f), FAUSTFLOAT(0.01f));
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("MASTER");
		ui_interface->declare(&fHslider14, "0", "");
		ui_interface->declare(&fHslider14, "style", "knob");
		ui_interface->declare(&fHslider14, "unit", "dB");
		ui_interface->addHorizontalSlider("Gain", &fHslider14, FAUSTFLOAT(-12.0f), FAUSTFLOAT(-6e+01f), FAUSTFLOAT(0.0f), FAUSTFLOAT(0.1f));
		ui_interface->closeBox();
		ui_interface->closeBox();
	}
	
	virtual void compute(int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		int iSlow0 = static_cast<int>(static_cast<float>(fEntry0));
		int iSlow1 = iSlow0 >= 3;
		int iSlow2 = iSlow0 >= 2;
		int iSlow3 = iSlow0 >= 1;
		float fSlow4 = static_cast<float>(fHslider0);
		float fSlow5 = static_cast<float>(fHslider1);
		float fSlow6 = static_cast<float>(fHslider2);
		int iSlow7 = std::min<int>(96000, std::max<int>(0, static_cast<int>(fConst0 * fSlow6))) + 1;
		float fSlow8 = 1.0f / std::tan(fConst1 * (1.2e+04f * static_cast<float>(fHslider3) + 5e+02f));
		float fSlow9 = 1.0f - fSlow8;
		float fSlow10 = 1.0f / (fSlow8 + 1.0f);
		float fSlow11 = static_cast<float>(fHslider4);
		float fSlow12 = std::tan(fConst1 * static_cast<float>(fHslider5));
		float fSlow13 = effect_faustpower2_f(fSlow12);
		float fSlow14 = 2.0f * (1.0f - 1.0f / fSlow13);
		float fSlow15 = 1.0f / fSlow12;
		float fSlow16 = (fSlow15 + -1.4142135f) / fSlow12 + 1.0f;
		float fSlow17 = (fSlow15 + 1.4142135f) / fSlow12 + 1.0f;
		float fSlow18 = 1.0f / fSlow17;
		float fSlow19 = 8.0f * static_cast<float>(fHslider6) + 1.0f;
		float fSlow20 = fSlow19 / (fSlow13 * fSlow17);
		float fSlow21 = 2.0f * (static_cast<float>(fHslider7) / fSlow19);
		float fSlow22 = static_cast<float>(fHslider8);
		float fSlow23 = fConst2 * fSlow22;
		float fSlow24 = 0.005f * static_cast<float>(fHslider9);
		float fSlow25 = fConst3 * fSlow22;
		float fSlow26 = static_cast<float>(fHslider10);
		float fSlow27 = 0.5f * fSlow26;
		float fSlow28 = 1.0f - fSlow26;
		float fSlow29 = static_cast<float>(fHslider11);
		float fSlow30 = 1.0f - fSlow29;
		float fSlow31 = 5.0f * fSlow5 + 0.5f;
		float fSlow32 = std::exp(-(fConst30 / fSlow31));
		float fSlow33 = effect_faustpower2_f(fSlow32);
		float fSlow34 = 1.0f - fSlow33;
		float fSlow35 = 1.0f - fConst31 * fSlow33;
		float fSlow36 = std::sqrt(std::max<float>(0.0f, effect_faustpower2_f(fSlow35) / effect_faustpower2_f(fSlow34) + -1.0f));
		float fSlow37 = fSlow35 / fSlow34;
		float fSlow38 = fSlow37 - fSlow36;
		float fSlow39 = std::exp(-(fConst35 / fSlow31)) / fSlow32 + -1.0f;
		float fSlow40 = fSlow32 * (fSlow36 + (1.0f - fSlow37));
		int iSlow41 = std::min<int>(96000, std::max<int>(0, static_cast<int>(fConst38 * fSlow6))) + 1;
		float fSlow42 = fConst39 * fSlow22;
		float fSlow43 = std::exp(-(fConst44 / fSlow31));
		float fSlow44 = effect_faustpower2_f(fSlow43);
		float fSlow45 = 1.0f - fSlow44;
		float fSlow46 = 1.0f - fConst31 * fSlow44;
		float fSlow47 = std::sqrt(std::max<float>(0.0f, effect_faustpower2_f(fSlow46) / effect_faustpower2_f(fSlow45) + -1.0f));
		float fSlow48 = fSlow46 / fSlow45;
		float fSlow49 = fSlow48 - fSlow47;
		float fSlow50 = std::exp(-(fConst45 / fSlow31)) / fSlow43 + -1.0f;
		float fSlow51 = fSlow43 * (fSlow47 + (1.0f - fSlow48));
		float fSlow52 = std::exp(-(fConst51 / fSlow31));
		float fSlow53 = effect_faustpower2_f(fSlow52);
		float fSlow54 = 1.0f - fSlow53;
		float fSlow55 = 1.0f - fConst31 * fSlow53;
		float fSlow56 = std::sqrt(std::max<float>(0.0f, effect_faustpower2_f(fSlow55) / effect_faustpower2_f(fSlow54) + -1.0f));
		float fSlow57 = fSlow55 / fSlow54;
		float fSlow58 = fSlow57 - fSlow56;
		float fSlow59 = std::exp(-(fConst52 / fSlow31)) / fSlow52 + -1.0f;
		float fSlow60 = fSlow52 * (fSlow56 + (1.0f - fSlow57));
		float fSlow61 = std::exp(-(fConst58 / fSlow31));
		float fSlow62 = effect_faustpower2_f(fSlow61);
		float fSlow63 = 1.0f - fSlow62;
		float fSlow64 = 1.0f - fConst31 * fSlow62;
		float fSlow65 = std::sqrt(std::max<float>(0.0f, effect_faustpower2_f(fSlow64) / effect_faustpower2_f(fSlow63) + -1.0f));
		float fSlow66 = fSlow64 / fSlow63;
		float fSlow67 = fSlow66 - fSlow65;
		float fSlow68 = std::exp(-(fConst59 / fSlow31)) / fSlow61 + -1.0f;
		float fSlow69 = fSlow61 * (fSlow65 + (1.0f - fSlow66));
		float fSlow70 = std::exp(-(fConst65 / fSlow31));
		float fSlow71 = effect_faustpower2_f(fSlow70);
		float fSlow72 = 1.0f - fSlow71;
		float fSlow73 = 1.0f - fConst31 * fSlow71;
		float fSlow74 = std::sqrt(std::max<float>(0.0f, effect_faustpower2_f(fSlow73) / effect_faustpower2_f(fSlow72) + -1.0f));
		float fSlow75 = fSlow73 / fSlow72;
		float fSlow76 = fSlow75 - fSlow74;
		float fSlow77 = std::exp(-(fConst66 / fSlow31)) / fSlow70 + -1.0f;
		float fSlow78 = fSlow70 * (fSlow74 + (1.0f - fSlow75));
		float fSlow79 = std::exp(-(fConst72 / fSlow31));
		float fSlow80 = effect_faustpower2_f(fSlow79);
		float fSlow81 = 1.0f - fSlow80;
		float fSlow82 = 1.0f - fConst31 * fSlow80;
		float fSlow83 = std::sqrt(std::max<float>(0.0f, effect_faustpower2_f(fSlow82) / effect_faustpower2_f(fSlow81) + -1.0f));
		float fSlow84 = fSlow82 / fSlow81;
		float fSlow85 = fSlow84 - fSlow83;
		float fSlow86 = std::exp(-(fConst73 / fSlow31)) / fSlow79 + -1.0f;
		float fSlow87 = fSlow79 * (fSlow83 + (1.0f - fSlow84));
		float fSlow88 = std::exp(-(fConst79 / fSlow31));
		float fSlow89 = effect_faustpower2_f(fSlow88);
		float fSlow90 = 1.0f - fSlow89;
		float fSlow91 = 1.0f - fConst31 * fSlow89;
		float fSlow92 = std::sqrt(std::max<float>(0.0f, effect_faustpower2_f(fSlow91) / effect_faustpower2_f(fSlow90) + -1.0f));
		float fSlow93 = fSlow91 / fSlow90;
		float fSlow94 = fSlow93 - fSlow92;
		float fSlow95 = std::exp(-(fConst80 / fSlow31)) / fSlow88 + -1.0f;
		float fSlow96 = fSlow88 * (fSlow92 + (1.0f - fSlow93));
		float fSlow97 = std::exp(-(fConst86 / fSlow31));
		float fSlow98 = effect_faustpower2_f(fSlow97);
		float fSlow99 = 1.0f - fSlow98;
		float fSlow100 = 1.0f - fConst31 * fSlow98;
		float fSlow101 = std::sqrt(std::max<float>(0.0f, effect_faustpower2_f(fSlow100) / effect_faustpower2_f(fSlow99) + -1.0f));
		float fSlow102 = fSlow100 / fSlow99;
		float fSlow103 = fSlow102 - fSlow101;
		float fSlow104 = std::exp(-(fConst87 / fSlow31)) / fSlow97 + -1.0f;
		float fSlow105 = fSlow97 * (fSlow101 + (1.0f - fSlow102));
		float fSlow106 = 1.0f - fSlow4;
		float fSlow107 = 0.65f * fSlow5 + 0.3f;
		int iSlow108 = iSlow0 >= 4;
		float fSlow109 = 2.0f * fSlow5 + 0.5f;
		int iSlow110 = itbl1effectSIG1[static_cast<int>(134.0f * fSlow109)];
		float fSlow111 = 0.005f * static_cast<float>(iSlow110);
		int iSlow112 = itbl1effectSIG1[static_cast<int>(54.0f * fSlow109)];
		float fSlow113 = 0.005f * static_cast<float>(iSlow112);
		int iSlow114 = itbl1effectSIG1[static_cast<int>(1e+01f * fSlow109)];
		float fSlow115 = 0.0001f * static_cast<float>(iSlow114);
		int iSlow116 = itbl1effectSIG1[static_cast<int>(1.1e+02f * fSlow109)];
		float fSlow117 = 0.0001f * static_cast<float>(iSlow116);
		int iSlow118 = itbl1effectSIG1[static_cast<int>(4e+01f * fSlow109)];
		float fSlow119 = 0.0001f * static_cast<float>(iSlow118);
		int iSlow120 = itbl1effectSIG1[static_cast<int>(1.4e+02f * fSlow109)];
		float fSlow121 = 0.0001f * static_cast<float>(iSlow120);
		int iSlow122 = itbl1effectSIG1[static_cast<int>(7e+01f * fSlow109)];
		float fSlow123 = 0.0001f * static_cast<float>(iSlow122);
		int iSlow124 = itbl1effectSIG1[static_cast<int>(1.7e+02f * fSlow109)];
		float fSlow125 = 0.0001f * static_cast<float>(iSlow124);
		int iSlow126 = itbl1effectSIG1[static_cast<int>(1e+02f * fSlow109)];
		float fSlow127 = 0.0001f * static_cast<float>(iSlow126);
		int iSlow128 = itbl1effectSIG1[static_cast<int>(2e+02f * fSlow109)];
		float fSlow129 = 0.0001f * static_cast<float>(iSlow128);
		int iSlow130 = itbl1effectSIG1[static_cast<int>(1.3e+02f * fSlow109)];
		float fSlow131 = 0.0001f * static_cast<float>(iSlow130);
		int iSlow132 = itbl1effectSIG1[static_cast<int>(2.3e+02f * fSlow109)];
		float fSlow133 = 0.0001f * static_cast<float>(iSlow132);
		float fSlow134 = static_cast<float>(fHslider12);
		float fSlow135 = 25.0f * fSlow134;
		int iSlow136 = itbl1effectSIG1[static_cast<int>(125.0f * fSlow109)];
		float fSlow137 = 0.0001f * static_cast<float>(iSlow136);
		int iSlow138 = itbl1effectSIG1[static_cast<int>(204.0f * fSlow109)];
		float fSlow139 = 0.005f * static_cast<float>(iSlow138);
		int iSlow140 = itbl1effectSIG1[static_cast<int>(25.0f * fSlow109)];
		float fSlow141 = 0.0001f * static_cast<float>(iSlow140);
		int iSlow142 = itbl1effectSIG1[static_cast<int>(155.0f * fSlow109)];
		float fSlow143 = 0.0001f * static_cast<float>(iSlow142);
		int iSlow144 = itbl1effectSIG1[static_cast<int>(55.0f * fSlow109)];
		float fSlow145 = 0.0001f * static_cast<float>(iSlow144);
		int iSlow146 = itbl1effectSIG1[static_cast<int>(185.0f * fSlow109)];
		float fSlow147 = 0.0001f * static_cast<float>(iSlow146);
		int iSlow148 = itbl1effectSIG1[static_cast<int>(85.0f * fSlow109)];
		float fSlow149 = 0.0001f * static_cast<float>(iSlow148);
		int iSlow150 = itbl1effectSIG1[static_cast<int>(215.0f * fSlow109)];
		float fSlow151 = 0.0001f * static_cast<float>(iSlow150);
		int iSlow152 = itbl1effectSIG1[static_cast<int>(115.0f * fSlow109)];
		float fSlow153 = 0.0001f * static_cast<float>(iSlow152);
		int iSlow154 = itbl1effectSIG1[static_cast<int>(245.0f * fSlow109)];
		float fSlow155 = 0.0001f * static_cast<float>(iSlow154);
		int iSlow156 = itbl1effectSIG1[static_cast<int>(145.0f * fSlow109)];
		float fSlow157 = 0.0001f * static_cast<float>(iSlow156);
		float fSlow158 = std::pow(1e+01f, -(0.51f * ((1.25f * fSlow109 + -0.25f) / fSlow31)));
		int iSlow159 = itbl1effectSIG1[static_cast<int>(34.0f * fSlow109)];
		float fSlow160 = 0.005f * static_cast<float>(iSlow159);
		int iSlow161 = itbl1effectSIG1[static_cast<int>(2.4e+02f * fSlow109)];
		float fSlow162 = 0.0001f * static_cast<float>(iSlow161);
		int iSlow163 = itbl1effectSIG1[static_cast<int>(1.9e+02f * fSlow109)];
		float fSlow164 = 0.0001f * static_cast<float>(iSlow163);
		int iSlow165 = itbl1effectSIG1[static_cast<int>(175.0f * fSlow109)];
		float fSlow166 = 0.0001f * static_cast<float>(iSlow165);
		float fSlow167 = 0.5f * fSlow5;
		float fSlow168 = fSlow167 + 0.3f;
		float fSlow169 = std::floor(std::min<float>(65533.0f, fConst0 * fSlow31));
		int iSlow170 = itbl1effectSIG1[static_cast<int>(49.0f * fSlow109)];
		float fSlow171 = 0.0001f * static_cast<float>(iSlow170);
		int iSlow172 = itbl1effectSIG1[static_cast<int>(59.0f * fSlow109)];
		float fSlow173 = 0.0001f * static_cast<float>(iSlow172);
		int iSlow174 = itbl1effectSIG1[static_cast<int>(36.0f * fSlow109)];
		float fSlow175 = 0.0001f * static_cast<float>(iSlow174);
		int iSlow176 = itbl1effectSIG1[static_cast<int>(46.0f * fSlow109)];
		float fSlow177 = 0.0001f * static_cast<float>(iSlow176);
		int iSlow178 = itbl1effectSIG1[static_cast<int>(23.0f * fSlow109)];
		float fSlow179 = 0.0001f * static_cast<float>(iSlow178);
		int iSlow180 = itbl1effectSIG1[static_cast<int>(33.0f * fSlow109)];
		float fSlow181 = 0.0001f * static_cast<float>(iSlow180);
		int iSlow182 = itbl1effectSIG1[static_cast<int>(2e+01f * fSlow109)];
		float fSlow183 = 0.0001f * static_cast<float>(iSlow182);
		int iSlow184 = itbl1effectSIG1[static_cast<int>(68.0f * fSlow109)];
		float fSlow185 = 0.0001f * static_cast<float>(iSlow184);
		int iSlow186 = itbl1effectSIG1[static_cast<int>(78.0f * fSlow109)];
		float fSlow187 = 0.0001f * static_cast<float>(iSlow186);
		int iSlow188 = itbl1effectSIG1[static_cast<int>(65.0f * fSlow109)];
		float fSlow189 = 0.0001f * static_cast<float>(iSlow188);
		int iSlow190 = itbl1effectSIG1[static_cast<int>(42.0f * fSlow109)];
		float fSlow191 = 0.0001f * static_cast<float>(iSlow190);
		int iSlow192 = itbl1effectSIG1[static_cast<int>(52.0f * fSlow109)];
		float fSlow193 = 0.0001f * static_cast<float>(iSlow192);
		int iSlow194 = itbl1effectSIG1[static_cast<int>(29.0f * fSlow109)];
		float fSlow195 = 0.0001f * static_cast<float>(iSlow194);
		int iSlow196 = itbl1effectSIG1[static_cast<int>(39.0f * fSlow109)];
		float fSlow197 = 0.0001f * static_cast<float>(iSlow196);
		int iSlow198 = itbl1effectSIG1[static_cast<int>(87.0f * fSlow109)];
		float fSlow199 = 0.0001f * static_cast<float>(iSlow198);
		int iSlow200 = itbl1effectSIG1[static_cast<int>(97.0f * fSlow109)];
		float fSlow201 = 0.0001f * static_cast<float>(iSlow200);
		int iSlow202 = itbl1effectSIG1[static_cast<int>(74.0f * fSlow109)];
		float fSlow203 = 0.0001f * static_cast<float>(iSlow202);
		int iSlow204 = itbl1effectSIG1[static_cast<int>(84.0f * fSlow109)];
		float fSlow205 = 0.0001f * static_cast<float>(iSlow204);
		int iSlow206 = itbl1effectSIG1[static_cast<int>(61.0f * fSlow109)];
		float fSlow207 = 0.0001f * static_cast<float>(iSlow206);
		int iSlow208 = itbl1effectSIG1[static_cast<int>(71.0f * fSlow109)];
		float fSlow209 = 0.0001f * static_cast<float>(iSlow208);
		int iSlow210 = itbl1effectSIG1[static_cast<int>(48.0f * fSlow109)];
		float fSlow211 = 0.0001f * static_cast<float>(iSlow210);
		int iSlow212 = itbl1effectSIG1[static_cast<int>(58.0f * fSlow109)];
		float fSlow213 = 0.0001f * static_cast<float>(iSlow212);
		float fSlow214 = static_cast<float>(fHslider13);
		float fSlow215 = 1.0f - fSlow214;
		float fSlow216 = std::pow(1e+01f, 0.05f * static_cast<float>(fHslider14));
		for (int i0 = 0; i0 < count; i0 = i0 + 1) {
			iVec0[0] = 2;
			iVec1[0] = 1;
			fVec2[0] = fSlow4;
			fVec3[0] = 0.5f;
			fRec9[0] = 0.5f * (fRec9[1] + fRec8[1]);
			float fTemp0 = fRec10[(IOTA0 - iSlow7) & 131071];
			fVec4[0] = fTemp0;
			fRec11[0] = -(fSlow10 * (fSlow9 * fRec11[1] - (fTemp0 + fVec4[1])));
			float fTemp1 = static_cast<float>(input0[i0]);
			fRec12[0] = fTemp1 - fSlow18 * (fSlow16 * fRec12[2] + fSlow14 * fRec12[1]);
			float fTemp2 = fTemp1 + fSlow21 * tanhf(fSlow20 * (fRec12[2] + (fRec12[0] - 2.0f * fRec12[1])));
			fVec5[IOTA0 & 4095] = fTemp2;
			int iTemp3 = 1 - iVec1[1];
			float fTemp4 = ((iTemp3) ? 0.0f : fSlow23 + fRec14[1]);
			fRec14[0] = fTemp4 - std::floor(fTemp4);
			float fTemp5 = fConst0 * (fSlow24 * (ftbl0effectSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec14[0]), 65535))] + 1.0f) + 0.007f);
			int iTemp6 = static_cast<int>(fTemp5);
			float fTemp7 = std::floor(fTemp5);
			float fTemp8 = ((iTemp3) ? 0.0f : fSlow25 + fRec15[1]);
			fRec15[0] = fTemp8 - std::floor(fTemp8);
			float fTemp9 = fConst0 * (fSlow24 * (ftbl0effectSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec15[0]), 65535))] + 1.0f) + 0.007f);
			int iTemp10 = static_cast<int>(fTemp9);
			int iTemp11 = std::min<int>(2049, std::max<int>(0, iTemp10 + 1));
			float fTemp12 = std::floor(fTemp9);
			float fTemp13 = fTemp9 - fTemp12;
			float fTemp14 = fTemp12 + (1.0f - fTemp9);
			int iTemp15 = std::min<int>(2049, std::max<int>(0, iTemp10));
			float fTemp16 = fSlow28 * fTemp2 + fSlow27 * (fVec5[(IOTA0 - iTemp15) & 4095] * fTemp14 + fTemp13 * fVec5[(IOTA0 - iTemp11) & 4095] + fVec5[(IOTA0 - std::min<int>(2049, std::max<int>(0, iTemp6))) & 4095] * (fTemp7 + (1.0f - fTemp5)) + (fTemp5 - fTemp7) * fVec5[(IOTA0 - std::min<int>(2049, std::max<int>(0, iTemp6 + 1))) & 4095]);
			fRec10[IOTA0 & 131071] = fTemp16 + fSlow11 * fRec11[0];
			float fTemp17 = fRec10[IOTA0 & 131071];
			float fTemp18 = fSlow30 * fTemp16 + fSlow29 * fTemp17;
			fVec7[IOTA0 & 8191] = fTemp18 + fSlow5 * fRec9[0];
			fRec8[0] = fVec7[(IOTA0 - iConst5) & 8191];
			fRec17[0] = 0.5f * (fRec17[1] + fRec16[1]);
			fVec8[IOTA0 & 8191] = fTemp18 + fSlow5 * fRec17[0];
			fRec16[0] = fVec8[(IOTA0 - iConst7) & 8191];
			fRec19[0] = 0.5f * (fRec19[1] + fRec18[1]);
			fVec9[IOTA0 & 8191] = fTemp18 + fSlow5 * fRec19[0];
			fRec18[0] = fVec9[(IOTA0 - iConst9) & 8191];
			fRec21[0] = 0.5f * (fRec21[1] + fRec20[1]);
			fVec10[IOTA0 & 8191] = fTemp18 + fSlow5 * fRec21[0];
			fRec20[0] = fVec10[(IOTA0 - iConst11) & 8191];
			fRec23[0] = 0.5f * (fRec23[1] + fRec22[1]);
			fVec11[IOTA0 & 8191] = fTemp18 + fSlow5 * fRec23[0];
			fRec22[0] = fVec11[(IOTA0 - iConst13) & 8191];
			fRec25[0] = 0.5f * (fRec25[1] + fRec24[1]);
			fVec12[IOTA0 & 8191] = fTemp18 + fSlow5 * fRec25[0];
			fRec24[0] = fVec12[(IOTA0 - iConst15) & 8191];
			fRec27[0] = 0.5f * (fRec27[1] + fRec26[1]);
			fVec13[IOTA0 & 8191] = fTemp18 + fSlow5 * fRec27[0];
			fRec26[0] = fVec13[(IOTA0 - iConst17) & 8191];
			fRec29[0] = 0.5f * (fRec29[1] + fRec28[1]);
			fVec14[IOTA0 & 8191] = fTemp18 + fSlow5 * fRec29[0];
			fRec28[0] = fVec14[(IOTA0 - iConst19) & 8191];
			float fTemp19 = fRec28[1] + fRec26[1] + fRec24[1] + fRec22[1] + fRec20[1] + fRec18[1] + fRec16[1] + fSlow4 * fRec6[1] + fRec8[1];
			fVec15[IOTA0 & 2047] = fTemp19;
			fRec6[0] = fVec15[(IOTA0 - iConst21) & 2047];
			float fRec7 = -(fSlow4 * fTemp19);
			float fTemp20 = fRec6[1] + fRec7 + fSlow4 * fRec4[1];
			fVec16[IOTA0 & 2047] = fTemp20;
			fRec4[0] = fVec16[(IOTA0 - iConst23) & 2047];
			float fRec5 = -(fSlow4 * fTemp20);
			float fTemp21 = fRec4[1] + fRec5 + fSlow4 * fRec2[1];
			fVec17[IOTA0 & 2047] = fTemp21;
			fRec2[0] = fVec17[(IOTA0 - iConst25) & 2047];
			float fRec3 = -(fSlow4 * fTemp21);
			float fTemp22 = fRec2[1] + fRec3 + fSlow4 * fRec0[1];
			fVec18[IOTA0 & 1023] = fTemp22;
			fRec0[0] = fVec18[(IOTA0 - iConst27) & 1023];
			float fRec1 = -(fSlow4 * fTemp22);
			fRec41[0] = -(fConst34 * (fConst33 * fRec41[1] - (fRec34[1] + fRec34[2])));
			fRec40[0] = fSlow40 * (fRec34[1] + fSlow39 * fRec41[0]) + fSlow38 * fRec40[1];
			fVec19[IOTA0 & 16383] = 0.35355338f * fRec40[0] + 1e-20f;
			float fTemp23 = fRec42[(IOTA0 - iSlow41) & 131071];
			fVec20[0] = fTemp23;
			fRec43[0] = -(fSlow10 * (fSlow9 * fRec43[1] - (fTemp23 + fVec20[1])));
			float fTemp24 = static_cast<float>(input1[i0]);
			fRec44[0] = fTemp24 - fSlow18 * (fSlow16 * fRec44[2] + fSlow14 * fRec44[1]);
			float fTemp25 = fTemp24 + fSlow21 * tanhf(fSlow20 * (fRec44[2] + (fRec44[0] - 2.0f * fRec44[1])));
			fVec21[IOTA0 & 4095] = fTemp25;
			float fTemp26 = ((iTemp3) ? 0.0f : fSlow42 + fRec45[1]);
			fRec45[0] = fTemp26 - std::floor(fTemp26);
			float fTemp27 = fConst0 * (fSlow24 * (ftbl0effectSIG0[std::max<int>(0, std::min<int>(static_cast<int>(65536.0f * fRec45[0]), 65535))] + 1.0f) + 0.007f);
			int iTemp28 = static_cast<int>(fTemp27);
			float fTemp29 = std::floor(fTemp27);
			float fTemp30 = fSlow28 * fTemp25 + fSlow27 * (fVec21[(IOTA0 - std::min<int>(2049, std::max<int>(0, iTemp28))) & 4095] * (fTemp29 + (1.0f - fTemp27)) + (fTemp27 - fTemp29) * fVec21[(IOTA0 - std::min<int>(2049, std::max<int>(0, iTemp28 + 1))) & 4095] + fTemp14 * fVec21[(IOTA0 - iTemp15) & 4095] + fTemp13 * fVec21[(IOTA0 - iTemp11) & 4095]);
			fRec42[IOTA0 & 131071] = fTemp30 + fSlow11 * fRec43[0];
			float fTemp31 = fRec42[IOTA0 & 131071];
			float fTemp32 = fSlow30 * (fTemp16 + fTemp30) + fSlow29 * (fTemp17 + fTemp31);
			fVec22[IOTA0 & 16383] = fTemp32;
			float fTemp33 = 0.15f * fVec22[(IOTA0 - iConst40) & 16383];
			float fTemp34 = fTemp33 + fVec19[(IOTA0 - iConst37) & 16383] - 0.6f * fRec38[1];
			fVec23[IOTA0 & 4095] = fTemp34;
			fRec38[0] = fVec23[(IOTA0 - iConst41) & 4095];
			float fRec39 = 0.6f * fTemp34;
			fRec49[0] = -(fConst34 * (fConst33 * fRec49[1] - (fRec30[1] + fRec30[2])));
			fRec48[0] = fSlow51 * (fRec30[1] + fSlow50 * fRec49[0]) + fSlow49 * fRec48[1];
			fVec24[IOTA0 & 16383] = 0.35355338f * fRec48[0] + 1e-20f;
			float fTemp35 = fVec24[(IOTA0 - iConst47) & 16383] + fTemp33 - 0.6f * fRec46[1];
			fVec25[IOTA0 & 2047] = fTemp35;
			fRec46[0] = fVec25[(IOTA0 - iConst48) & 2047];
			float fRec47 = 0.6f * fTemp35;
			float fTemp36 = fRec47 + fRec39;
			fRec53[0] = -(fConst34 * (fConst33 * fRec53[1] - (fRec32[1] + fRec32[2])));
			fRec52[0] = fSlow60 * (fRec32[1] + fSlow59 * fRec53[0]) + fSlow58 * fRec52[1];
			fVec26[IOTA0 & 16383] = 0.35355338f * fRec52[0] + 1e-20f;
			float fTemp37 = fVec26[(IOTA0 - iConst54) & 16383] - (fTemp33 + 0.6f * fRec50[1]);
			fVec27[IOTA0 & 4095] = fTemp37;
			fRec50[0] = fVec27[(IOTA0 - iConst55) & 4095];
			float fRec51 = 0.6f * fTemp37;
			fRec57[0] = -(fConst34 * (fConst33 * fRec57[1] - (fRec36[1] + fRec36[2])));
			fRec56[0] = fSlow69 * (fRec36[1] + fSlow68 * fRec57[0]) + fSlow67 * fRec56[1];
			fVec28[IOTA0 & 16383] = 0.35355338f * fRec56[0] + 1e-20f;
			float fTemp38 = fVec28[(IOTA0 - iConst61) & 16383] - (fTemp33 + 0.6f * fRec54[1]);
			fVec29[IOTA0 & 2047] = fTemp38;
			fRec54[0] = fVec29[(IOTA0 - iConst62) & 2047];
			float fRec55 = 0.6f * fTemp38;
			float fTemp39 = fRec55 + fRec51 + fTemp36;
			fRec61[0] = -(fConst34 * (fConst33 * fRec61[1] - (fRec31[1] + fRec31[2])));
			fRec60[0] = fSlow78 * (fRec31[1] + fSlow77 * fRec61[0]) + fSlow76 * fRec60[1];
			fVec30[IOTA0 & 32767] = 0.35355338f * fRec60[0] + 1e-20f;
			float fTemp40 = fVec30[(IOTA0 - iConst68) & 32767] + fTemp33 + 0.6f * fRec58[1];
			fVec31[IOTA0 & 4095] = fTemp40;
			fRec58[0] = fVec31[(IOTA0 - iConst69) & 4095];
			float fRec59 = -(0.6f * fTemp40);
			fRec65[0] = -(fConst34 * (fConst33 * fRec65[1] - (fRec35[1] + fRec35[2])));
			fRec64[0] = fSlow87 * (fRec35[1] + fSlow86 * fRec65[0]) + fSlow85 * fRec64[1];
			fVec32[IOTA0 & 16383] = 0.35355338f * fRec64[0] + 1e-20f;
			float fTemp41 = fVec32[(IOTA0 - iConst75) & 16383] + fTemp33 + 0.6f * fRec62[1];
			fVec33[IOTA0 & 4095] = fTemp41;
			fRec62[0] = fVec33[(IOTA0 - iConst76) & 4095];
			float fRec63 = -(0.6f * fTemp41);
			fRec69[0] = -(fConst34 * (fConst33 * fRec69[1] - (fRec33[1] + fRec33[2])));
			fRec68[0] = fSlow96 * (fRec33[1] + fSlow95 * fRec69[0]) + fSlow94 * fRec68[1];
			fVec34[IOTA0 & 32767] = 0.35355338f * fRec68[0] + 1e-20f;
			float fTemp42 = 0.6f * fRec66[1] + fVec34[(IOTA0 - iConst82) & 32767];
			fVec35[IOTA0 & 4095] = fTemp42 - fTemp33;
			fRec66[0] = fVec35[(IOTA0 - iConst83) & 4095];
			float fRec67 = 0.6f * (fTemp33 - fTemp42);
			fRec73[0] = -(fConst34 * (fConst33 * fRec73[1] - (fRec37[1] + fRec37[2])));
			fRec72[0] = fSlow105 * (fRec37[1] + fSlow104 * fRec73[0]) + fSlow103 * fRec72[1];
			fVec36[IOTA0 & 32767] = 0.35355338f * fRec72[0] + 1e-20f;
			float fTemp43 = 0.6f * fRec70[1] + fVec36[(IOTA0 - iConst89) & 32767];
			fVec37[IOTA0 & 2047] = fTemp43 - fTemp33;
			fRec70[0] = fVec37[(IOTA0 - iConst90) & 2047];
			float fRec71 = 0.6f * (fTemp33 - fTemp43);
			fRec30[0] = fRec70[1] + fRec66[1] + fRec62[1] + fRec58[1] + fRec54[1] + fRec50[1] + fRec38[1] + fRec46[1] + fRec71 + fRec67 + fRec63 + fRec59 + fTemp39;
			fRec31[0] = fRec54[1] + fRec50[1] + fRec38[1] + fRec46[1] + fTemp39 - (fRec70[1] + fRec66[1] + fRec62[1] + fRec58[1] + fRec71 + fRec67 + fRec59 + fRec63);
			float fTemp44 = fRec51 + fRec55;
			fRec32[0] = fRec62[1] + fRec58[1] + fRec38[1] + fRec46[1] + fRec63 + fRec59 + fTemp36 - (fRec70[1] + fRec66[1] + fRec54[1] + fRec50[1] + fRec71 + fRec67 + fTemp44);
			fRec33[0] = fRec70[1] + fRec66[1] + fRec38[1] + fRec46[1] + fRec71 + fRec67 + fTemp36 - (fRec62[1] + fRec58[1] + fRec54[1] + fRec50[1] + fRec63 + fRec59 + fTemp44);
			float fTemp45 = fRec39 + fRec55;
			float fTemp46 = fRec47 + fRec51;
			fRec34[0] = fRec66[1] + fRec58[1] + fRec50[1] + fRec46[1] + fRec67 + fRec59 + fTemp46 - (fRec70[1] + fRec62[1] + fRec54[1] + fRec38[1] + fRec71 + fRec63 + fTemp45);
			fRec35[0] = fRec70[1] + fRec62[1] + fRec50[1] + fRec46[1] + fRec71 + fRec63 + fTemp46 - (fRec66[1] + fRec58[1] + fRec54[1] + fRec38[1] + fRec67 + fRec59 + fTemp45);
			float fTemp47 = fRec39 + fRec51;
			float fTemp48 = fRec47 + fRec55;
			fRec36[0] = fRec70[1] + fRec58[1] + fRec54[1] + fRec46[1] + fRec71 + fRec59 + fTemp48 - (fRec66[1] + fRec62[1] + fRec50[1] + fRec38[1] + fRec67 + fRec63 + fTemp47);
			fRec37[0] = fRec66[1] + fRec62[1] + fRec54[1] + fRec46[1] + fRec67 + fRec63 + fTemp48 - (fRec70[1] + fRec58[1] + fRec50[1] + fRec38[1] + fRec71 + fRec59 + fTemp47);
			float fTemp49 = 0.7f * fRec79[1] + fRec75[1];
			fVec38[IOTA0 & 1023] = fTemp49;
			fRec79[0] = fVec38[(IOTA0 - 908) & 1023];
			float fRec80 = -(0.7f * fTemp49);
			fVec39[IOTA0 & 8191] = fRec80 + fRec79[1];
			fRec78[0] = fSlow4 * fRec78[1] + fSlow106 * fVec39[(IOTA0 - 4217) & 8191];
			float fTemp50 = fSlow107 * fRec78[0] - 0.5f * fRec76[1];
			fVec40[IOTA0 & 4095] = fTemp50;
			fRec76[0] = fVec40[(IOTA0 - 2656) & 4095];
			float fRec77 = 0.5f * fTemp50;
			fVec41[IOTA0 & 4095] = fRec77 + fRec76[1];
			fRec89[0] = 0.3f * fRec89[2] + 0.35f * fTemp32;
			float fTemp51 = fRec89[0] - 0.625f * fRec87[1];
			fVec42[IOTA0 & 255] = fTemp51;
			fRec87[0] = fVec42[(IOTA0 - 142) & 255];
			float fRec88 = 0.625f * fTemp51;
			float fTemp52 = fRec88 + fRec87[1] - 0.625f * fRec85[1];
			fVec43[IOTA0 & 127] = fTemp52;
			fRec85[0] = fVec43[(IOTA0 - 107) & 127];
			float fRec86 = 0.625f * fTemp52;
			float fTemp53 = fRec86 + fRec85[1] - 0.625f * fRec83[1];
			fVec44[IOTA0 & 511] = fTemp53;
			fRec83[0] = fVec44[(IOTA0 - 379) & 511];
			float fRec84 = 0.625f * fTemp53;
			float fTemp54 = fRec84 + fRec83[1] - 0.625f * fRec81[1];
			fVec45[IOTA0 & 511] = fTemp54;
			fRec81[0] = fVec45[(IOTA0 - 277) & 511];
			float fRec82 = 0.625f * fTemp54;
			fRec74[0] = fRec81[1] + fRec82 + fSlow107 * fVec41[(IOTA0 - 2656) & 4095];
			float fTemp55 = 0.7f * fRec93[1] + fRec74[1];
			fVec46[IOTA0 & 1023] = fTemp55;
			fRec93[0] = fVec46[(IOTA0 - 672) & 1023];
			float fRec94 = -(0.7f * fTemp55);
			fVec47[IOTA0 & 8191] = fRec94 + fRec93[1];
			fRec92[0] = fSlow4 * fRec92[1] + fSlow106 * fVec47[(IOTA0 - 4453) & 8191];
			float fTemp56 = fSlow107 * fRec92[0] - 0.5f * fRec90[1];
			fVec48[IOTA0 & 2047] = fTemp56;
			fRec90[0] = fVec48[(IOTA0 - 1800) & 2047];
			float fRec91 = 0.5f * fTemp56;
			fVec49[IOTA0 & 2047] = fRec91 + fRec90[1];
			fRec75[0] = fRec82 + fRec81[1] + fSlow107 * fVec49[(IOTA0 - 1800) & 2047];
			fRec105[0] = 0.995f * (fRec105[1] + static_cast<float>(iTemp3 * iSlow110)) + fSlow111;
			float fTemp57 = fRec105[0] + -1.49999f;
			float fTemp58 = std::floor(fTemp57);
			fRec107[0] = 0.995f * (fRec107[1] + static_cast<float>(iTemp3 * iSlow112)) + fSlow113;
			float fTemp59 = fRec107[0] + -1.49999f;
			float fTemp60 = std::floor(fTemp59);
			fRec111[0] = 0.9999f * (fRec111[1] + static_cast<float>(iTemp3 * iSlow114)) + fSlow115;
			float fTemp61 = fRec111[0] + -1.49999f;
			float fTemp62 = std::floor(fTemp61);
			float fTemp63 = fRec111[0] - fTemp62;
			float fTemp64 = fTemp62 + (2.0f - fRec111[0]);
			float fTemp65 = 0.7602446f * fRec96[1];
			float fTemp66 = 0.6496369f * fRec109[1];
			float fTemp67 = 0.7602446f * fRec95[1] - 0.6496369f * fRec108[1];
			fVec50[IOTA0 & 16383] = fTemp67 + (fTemp66 - fTemp65);
			int iTemp68 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp61)));
			float fTemp69 = fVec50[(IOTA0 - iTemp68) & 16383];
			fVec51[0] = fTemp69;
			fRec110[0] = 0.70710677f * (fTemp64 * fTemp69 / fTemp63 + fVec51[1]) - fRec110[1] * fTemp64 / fTemp63;
			fRec108[0] = fRec110[0];
			fRec113[0] = 0.9999f * (fRec113[1] + static_cast<float>(iTemp3 * iSlow116)) + fSlow117;
			float fTemp70 = fRec113[0] + -1.49999f;
			float fTemp71 = std::floor(fTemp70);
			float fTemp72 = fRec113[0] - fTemp71;
			float fTemp73 = fTemp71 + (2.0f - fRec113[0]);
			fVec52[IOTA0 & 16383] = fTemp67 + (fTemp65 - fTemp66);
			float fTemp74 = fVec52[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp70)))) & 16383];
			fVec53[0] = fTemp74;
			fRec112[0] = 0.70710677f * (fTemp73 * fTemp74 / fTemp72 + fVec53[1]) - fRec112[1] * fTemp73 / fTemp72;
			fRec109[0] = fRec112[0];
			float fTemp75 = 0.7602446f * fRec108[1] + 0.6496369f * fRec95[1];
			fRec117[0] = 0.9999f * (fRec117[1] + static_cast<float>(iTemp3 * iSlow118)) + fSlow119;
			float fTemp76 = fRec117[0] + -1.49999f;
			float fTemp77 = std::floor(fTemp76);
			float fTemp78 = fRec117[0] - fTemp77;
			float fTemp79 = fTemp77 + (2.0f - fRec117[0]);
			float fTemp80 = 0.7602446f * fRec109[1] + 0.6496369f * fRec96[1];
			float fTemp81 = 0.7602446f * fTemp80;
			float fTemp82 = 0.6496369f * fRec115[1];
			float fTemp83 = 0.7602446f * fTemp75 - 0.6496369f * fRec114[1];
			fVec54[IOTA0 & 16383] = fTemp83 + (fTemp82 - fTemp81);
			float fTemp84 = fVec54[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp76)))) & 16383];
			fVec55[0] = fTemp84;
			fRec116[0] = 0.70710677f * (fTemp79 * fTemp84 / fTemp78 + fVec55[1]) - fRec116[1] * fTemp79 / fTemp78;
			fRec114[0] = fRec116[0];
			fRec119[0] = 0.9999f * (fRec119[1] + static_cast<float>(iTemp3 * iSlow120)) + fSlow121;
			float fTemp85 = fRec119[0] + -1.49999f;
			float fTemp86 = std::floor(fTemp85);
			float fTemp87 = fRec119[0] - fTemp86;
			float fTemp88 = fTemp86 + (2.0f - fRec119[0]);
			fVec56[IOTA0 & 16383] = fTemp83 + (fTemp81 - fTemp82);
			float fTemp89 = fVec56[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp85)))) & 16383];
			fVec57[0] = fTemp89;
			fRec118[0] = 0.70710677f * (fTemp88 * fTemp89 / fTemp87 + fVec57[1]) - fRec118[1] * fTemp88 / fTemp87;
			fRec115[0] = fRec118[0];
			float fTemp90 = 0.7602446f * fRec114[1] + 0.6496369f * fTemp75;
			fRec123[0] = 0.9999f * (fRec123[1] + static_cast<float>(iTemp3 * iSlow122)) + fSlow123;
			float fTemp91 = fRec123[0] + -1.49999f;
			float fTemp92 = std::floor(fTemp91);
			float fTemp93 = fRec123[0] - fTemp92;
			float fTemp94 = fTemp92 + (2.0f - fRec123[0]);
			float fTemp95 = 0.7602446f * fRec115[1] + 0.6496369f * fTemp80;
			float fTemp96 = 0.7602446f * fTemp95;
			float fTemp97 = 0.6496369f * fRec121[1];
			float fTemp98 = 0.7602446f * fTemp90 - 0.6496369f * fRec120[1];
			fVec58[IOTA0 & 16383] = fTemp98 + (fTemp97 - fTemp96);
			float fTemp99 = fVec58[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp91)))) & 16383];
			fVec59[0] = fTemp99;
			fRec122[0] = 0.70710677f * (fTemp94 * fTemp99 / fTemp93 + fVec59[1]) - fRec122[1] * fTemp94 / fTemp93;
			fRec120[0] = fRec122[0];
			fRec125[0] = 0.9999f * (fRec125[1] + static_cast<float>(iTemp3 * iSlow124)) + fSlow125;
			float fTemp100 = fRec125[0] + -1.49999f;
			float fTemp101 = std::floor(fTemp100);
			float fTemp102 = fRec125[0] - fTemp101;
			float fTemp103 = fTemp101 + (2.0f - fRec125[0]);
			fVec60[IOTA0 & 16383] = fTemp98 + (fTemp96 - fTemp97);
			float fTemp104 = fVec60[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp100)))) & 16383];
			fVec61[0] = fTemp104;
			fRec124[0] = 0.70710677f * (fTemp103 * fTemp104 / fTemp102 + fVec61[1]) - fRec124[1] * fTemp103 / fTemp102;
			fRec121[0] = fRec124[0];
			float fTemp105 = 0.7602446f * fRec120[1] + 0.6496369f * fTemp90;
			fRec129[0] = 0.9999f * (fRec129[1] + static_cast<float>(iTemp3 * iSlow126)) + fSlow127;
			float fTemp106 = fRec129[0] + -1.49999f;
			float fTemp107 = std::floor(fTemp106);
			float fTemp108 = fRec129[0] - fTemp107;
			float fTemp109 = fTemp107 + (2.0f - fRec129[0]);
			float fTemp110 = 0.7602446f * fRec121[1] + 0.6496369f * fTemp95;
			float fTemp111 = 0.7602446f * fTemp110;
			float fTemp112 = 0.6496369f * fRec127[1];
			float fTemp113 = 0.7602446f * fTemp105 - 0.6496369f * fRec126[1];
			fVec62[IOTA0 & 16383] = fTemp113 + (fTemp112 - fTemp111);
			float fTemp114 = fVec62[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp106)))) & 16383];
			fVec63[0] = fTemp114;
			fRec128[0] = 0.70710677f * (fTemp109 * fTemp114 / fTemp108 + fVec63[1]) - fRec128[1] * fTemp109 / fTemp108;
			fRec126[0] = fRec128[0];
			fRec131[0] = 0.9999f * (fRec131[1] + static_cast<float>(iTemp3 * iSlow128)) + fSlow129;
			float fTemp115 = fRec131[0] + -1.49999f;
			float fTemp116 = std::floor(fTemp115);
			float fTemp117 = fRec131[0] - fTemp116;
			float fTemp118 = fTemp116 + (2.0f - fRec131[0]);
			fVec64[IOTA0 & 16383] = fTemp113 + (fTemp111 - fTemp112);
			float fTemp119 = fVec64[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp115)))) & 16383];
			fVec65[0] = fTemp119;
			fRec130[0] = 0.70710677f * (fTemp118 * fTemp119 / fTemp117 + fVec65[1]) - fRec130[1] * fTemp118 / fTemp117;
			fRec127[0] = fRec130[0];
			float fTemp120 = 0.7602446f * fRec126[1] + 0.6496369f * fTemp105;
			fRec135[0] = 0.9999f * (fRec135[1] + static_cast<float>(iTemp3 * iSlow130)) + fSlow131;
			float fTemp121 = fRec135[0] + -1.49999f;
			float fTemp122 = std::floor(fTemp121);
			float fTemp123 = fRec135[0] - fTemp122;
			float fTemp124 = fTemp122 + (2.0f - fRec135[0]);
			float fTemp125 = 0.7602446f * fRec127[1] + 0.6496369f * fTemp110;
			float fTemp126 = 0.7602446f * fTemp125;
			float fTemp127 = 0.6496369f * fRec133[1];
			float fTemp128 = 0.7602446f * fTemp120 - 0.6496369f * fRec132[1];
			fVec66[IOTA0 & 16383] = fTemp128 + (fTemp127 - fTemp126);
			float fTemp129 = fVec66[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp121)))) & 16383];
			fVec67[0] = fTemp129;
			fRec134[0] = 0.70710677f * (fTemp124 * fTemp129 / fTemp123 + fVec67[1]) - fRec134[1] * fTemp124 / fTemp123;
			fRec132[0] = fRec134[0];
			fRec137[0] = 0.9999f * (fRec137[1] + static_cast<float>(iTemp3 * iSlow132)) + fSlow133;
			float fTemp130 = fRec137[0] + -1.49999f;
			float fTemp131 = std::floor(fTemp130);
			float fTemp132 = fRec137[0] - fTemp131;
			float fTemp133 = fTemp131 + (2.0f - fRec137[0]);
			fVec68[IOTA0 & 16383] = fTemp128 + (fTemp126 - fTemp127);
			float fTemp134 = fVec68[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp130)))) & 16383];
			fVec69[0] = fTemp134;
			fRec136[0] = 0.70710677f * (fTemp133 * fTemp134 / fTemp132 + fVec69[1]) - fRec136[1] * fTemp133 / fTemp132;
			fRec133[0] = fRec136[0];
			float fTemp135 = 0.7602446f * fRec132[1] + 0.6496369f * fTemp120;
			fVec70[IOTA0 & 1023] = fTemp135;
			fRec138[0] = fConst113 * fRec139[1] + fConst112 * fRec138[1];
			float fTemp136 = static_cast<float>(iTemp3);
			fRec139[0] = fTemp136 + fConst112 * fRec139[1] - fConst113 * fRec138[1];
			fVec71[0] = fSlow134;
			float fTemp137 = fSlow135 * (fRec139[0] + 1.0f);
			float fTemp138 = fTemp137 + 3.500005f;
			int iTemp139 = static_cast<int>(fTemp138);
			int iTemp140 = std::min<int>(512, std::max<int>(0, iTemp139 + 4));
			float fTemp141 = std::floor(fTemp138);
			float fTemp142 = fTemp137 + (2.0f - fTemp141);
			float fTemp143 = fTemp137 + (3.0f - fTemp141);
			float fTemp144 = fTemp137 + (4.0f - fTemp141);
			float fTemp145 = fTemp137 + (5.0f - fTemp141);
			float fTemp146 = fTemp145 * fTemp144;
			float fTemp147 = fTemp146 * fTemp143;
			float fTemp148 = fTemp147 * fTemp142;
			int iTemp149 = std::min<int>(512, std::max<int>(0, iTemp139 + 3));
			int iTemp150 = std::min<int>(512, std::max<int>(0, iTemp139 + 2));
			int iTemp151 = std::min<int>(512, std::max<int>(0, iTemp139 + 1));
			int iTemp152 = std::min<int>(512, std::max<int>(0, iTemp139));
			float fTemp153 = fTemp137 + (1.0f - fTemp141);
			fVec72[IOTA0 & 16383] = fTemp153 * (fTemp142 * (fTemp143 * (0.041666668f * fVec70[(IOTA0 - iTemp152) & 1023] * fTemp144 - 0.16666667f * fTemp145 * fVec70[(IOTA0 - iTemp151) & 1023]) + 0.25f * fTemp146 * fVec70[(IOTA0 - iTemp150) & 1023]) - 0.16666667f * fTemp147 * fVec70[(IOTA0 - iTemp149) & 1023]) + 0.041666668f * fTemp148 * fVec70[(IOTA0 - iTemp140) & 1023];
			float fTemp154 = fVec72[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp59)))) & 16383];
			fVec73[0] = fTemp154;
			fRec106[0] = fVec73[1] - (fTemp60 + (2.0f - fRec107[0])) * (fRec106[1] - fTemp154) / (fRec107[0] - fTemp60);
			fRec143[0] = 0.9999f * (fRec143[1] + static_cast<float>(iTemp3 * iSlow136)) + fSlow137;
			float fTemp155 = fRec143[0] + -1.49999f;
			float fTemp156 = std::floor(fTemp155);
			float fTemp157 = fRec143[0] - fTemp156;
			float fTemp158 = fTemp156 + (2.0f - fRec143[0]);
			fRec145[0] = 0.995f * (fRec145[1] + static_cast<float>(iTemp3 * iSlow138)) + fSlow139;
			float fTemp159 = fRec145[0] + -1.49999f;
			float fTemp160 = std::floor(fTemp159);
			float fTemp161 = 0.7602446f * fRec133[1] + 0.6496369f * fTemp125;
			fVec74[IOTA0 & 1023] = fTemp161;
			float fTemp162 = fSlow135 * (1.0f - fRec139[0]);
			float fTemp163 = fTemp162 + 3.500005f;
			int iTemp164 = static_cast<int>(fTemp163);
			float fTemp165 = std::floor(fTemp163);
			float fTemp166 = fTemp162 + (2.0f - fTemp165);
			float fTemp167 = fTemp162 + (3.0f - fTemp165);
			float fTemp168 = fTemp162 + (4.0f - fTemp165);
			float fTemp169 = fTemp162 + (5.0f - fTemp165);
			float fTemp170 = fTemp169 * fTemp168;
			float fTemp171 = fTemp170 * fTemp167;
			fVec75[IOTA0 & 16383] = (fTemp162 + (1.0f - fTemp165)) * (fTemp166 * (fTemp167 * (0.041666668f * fVec74[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp164))) & 1023] * fTemp168 - 0.16666667f * fTemp169 * fVec74[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp164 + 1))) & 1023]) + 0.25f * fTemp170 * fVec74[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp164 + 2))) & 1023]) - 0.16666667f * fTemp171 * fVec74[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp164 + 3))) & 1023]) + 0.041666668f * fTemp171 * fTemp166 * fVec74[(IOTA0 - std::min<int>(512, std::max<int>(0, iTemp164 + 4))) & 1023];
			float fTemp172 = fVec75[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp159)))) & 16383];
			fVec76[0] = fTemp172;
			fRec144[0] = fVec76[1] - (fTemp160 + (2.0f - fRec145[0])) * (fRec144[1] - fTemp172) / (fRec145[0] - fTemp160);
			float fTemp173 = 0.7602446f * fRec144[0];
			float fTemp174 = 0.6496369f * fRec141[1];
			float fTemp175 = 0.7602446f * fRec106[0] - 0.6496369f * fRec140[1];
			fVec77[IOTA0 & 16383] = fTemp175 + (fTemp174 - fTemp173);
			float fTemp176 = fVec77[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp155)))) & 16383];
			fVec78[0] = fTemp176;
			fRec142[0] = 0.70710677f * (fTemp158 * fTemp176 / fTemp157 + fVec78[1]) - fRec142[1] * fTemp158 / fTemp157;
			fRec140[0] = fRec142[0];
			fRec147[0] = 0.9999f * (fRec147[1] + static_cast<float>(iTemp3 * iSlow140)) + fSlow141;
			float fTemp177 = fRec147[0] + -1.49999f;
			float fTemp178 = std::floor(fTemp177);
			float fTemp179 = fRec147[0] - fTemp178;
			float fTemp180 = fTemp178 + (2.0f - fRec147[0]);
			fVec79[IOTA0 & 16383] = fTemp175 + (fTemp173 - fTemp174);
			float fTemp181 = fVec79[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp177)))) & 16383];
			fVec80[0] = fTemp181;
			fRec146[0] = 0.70710677f * (fTemp180 * fTemp181 / fTemp179 + fVec80[1]) - fRec146[1] * fTemp180 / fTemp179;
			fRec141[0] = fRec146[0];
			float fTemp182 = 0.7602446f * fRec140[1] + 0.6496369f * fRec106[0];
			fRec151[0] = 0.9999f * (fRec151[1] + static_cast<float>(iTemp3 * iSlow142)) + fSlow143;
			float fTemp183 = fRec151[0] + -1.49999f;
			float fTemp184 = std::floor(fTemp183);
			float fTemp185 = fRec151[0] - fTemp184;
			float fTemp186 = fTemp184 + (2.0f - fRec151[0]);
			float fTemp187 = 0.7602446f * fRec141[1] + 0.6496369f * fRec144[0];
			float fTemp188 = 0.7602446f * fTemp187;
			float fTemp189 = 0.6496369f * fRec149[1];
			float fTemp190 = 0.7602446f * fTemp182 - 0.6496369f * fRec148[1];
			fVec81[IOTA0 & 16383] = fTemp190 + (fTemp189 - fTemp188);
			float fTemp191 = fVec81[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp183)))) & 16383];
			fVec82[0] = fTemp191;
			fRec150[0] = 0.70710677f * (fTemp186 * fTemp191 / fTemp185 + fVec82[1]) - fRec150[1] * fTemp186 / fTemp185;
			fRec148[0] = fRec150[0];
			fRec153[0] = 0.9999f * (fRec153[1] + static_cast<float>(iTemp3 * iSlow144)) + fSlow145;
			float fTemp192 = fRec153[0] + -1.49999f;
			float fTemp193 = std::floor(fTemp192);
			float fTemp194 = fRec153[0] - fTemp193;
			float fTemp195 = fTemp193 + (2.0f - fRec153[0]);
			fVec83[IOTA0 & 16383] = fTemp190 + (fTemp188 - fTemp189);
			int iTemp196 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp192)));
			float fTemp197 = fVec83[(IOTA0 - iTemp196) & 16383];
			fVec84[0] = fTemp197;
			fRec152[0] = 0.70710677f * (fTemp195 * fTemp197 / fTemp194 + fVec84[1]) - fTemp195 * fRec152[1] / fTemp194;
			fRec149[0] = fRec152[0];
			float fTemp198 = 0.7602446f * fRec148[1] + 0.6496369f * fTemp182;
			fRec157[0] = 0.9999f * (fRec157[1] + static_cast<float>(iTemp3 * iSlow146)) + fSlow147;
			float fTemp199 = fRec157[0] + -1.49999f;
			float fTemp200 = std::floor(fTemp199);
			float fTemp201 = fRec157[0] - fTemp200;
			float fTemp202 = fTemp200 + (2.0f - fRec157[0]);
			float fTemp203 = 0.7602446f * fRec149[1] + 0.6496369f * fTemp187;
			float fTemp204 = 0.7602446f * fTemp203;
			float fTemp205 = 0.6496369f * fRec155[1];
			float fTemp206 = 0.7602446f * fTemp198 - 0.6496369f * fRec154[1];
			fVec85[IOTA0 & 16383] = fTemp206 + (fTemp205 - fTemp204);
			float fTemp207 = fVec85[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp199)))) & 16383];
			fVec86[0] = fTemp207;
			fRec156[0] = 0.70710677f * (fTemp202 * fTemp207 / fTemp201 + fVec86[1]) - fRec156[1] * fTemp202 / fTemp201;
			fRec154[0] = fRec156[0];
			fRec159[0] = 0.9999f * (fRec159[1] + static_cast<float>(iTemp3 * iSlow148)) + fSlow149;
			float fTemp208 = fRec159[0] + -1.49999f;
			float fTemp209 = std::floor(fTemp208);
			float fTemp210 = fRec159[0] - fTemp209;
			float fTemp211 = fTemp209 + (2.0f - fRec159[0]);
			fVec87[IOTA0 & 16383] = fTemp206 + (fTemp204 - fTemp205);
			int iTemp212 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp208)));
			float fTemp213 = fVec87[(IOTA0 - iTemp212) & 16383];
			fVec88[0] = fTemp213;
			fRec158[0] = 0.70710677f * (fTemp211 * fTemp213 / fTemp210 + fVec88[1]) - fRec158[1] * fTemp211 / fTemp210;
			fRec155[0] = fRec158[0];
			float fTemp214 = 0.7602446f * fRec154[1] + 0.6496369f * fTemp198;
			fRec163[0] = 0.9999f * (fRec163[1] + static_cast<float>(iTemp3 * iSlow150)) + fSlow151;
			float fTemp215 = fRec163[0] + -1.49999f;
			float fTemp216 = std::floor(fTemp215);
			float fTemp217 = fRec163[0] - fTemp216;
			float fTemp218 = fTemp216 + (2.0f - fRec163[0]);
			float fTemp219 = 0.7602446f * fRec155[1] + 0.6496369f * fTemp203;
			float fTemp220 = 0.7602446f * fTemp219;
			float fTemp221 = 0.6496369f * fRec161[1];
			float fTemp222 = 0.7602446f * fTemp214 - 0.6496369f * fRec160[1];
			fVec89[IOTA0 & 16383] = fTemp222 + (fTemp221 - fTemp220);
			int iTemp223 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp215)));
			float fTemp224 = fVec89[(IOTA0 - iTemp223) & 16383];
			fVec90[0] = fTemp224;
			fRec162[0] = 0.70710677f * (fTemp218 * fTemp224 / fTemp217 + fVec90[1]) - fTemp218 * fRec162[1] / fTemp217;
			fRec160[0] = fRec162[0];
			fRec165[0] = 0.9999f * (fRec165[1] + static_cast<float>(iTemp3 * iSlow152)) + fSlow153;
			float fTemp225 = fRec165[0] + -1.49999f;
			float fTemp226 = std::floor(fTemp225);
			float fTemp227 = fRec165[0] - fTemp226;
			float fTemp228 = fTemp226 + (2.0f - fRec165[0]);
			fVec91[IOTA0 & 16383] = fTemp222 + (fTemp220 - fTemp221);
			int iTemp229 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp225)));
			float fTemp230 = fVec91[(IOTA0 - iTemp229) & 16383];
			fVec92[0] = fTemp230;
			fRec164[0] = 0.70710677f * (fTemp228 * fTemp230 / fTemp227 + fVec92[1]) - fTemp228 * fRec164[1] / fTemp227;
			fRec161[0] = fRec164[0];
			float fTemp231 = 0.7602446f * fRec160[1] + 0.6496369f * fTemp214;
			fRec169[0] = 0.9999f * (fRec169[1] + static_cast<float>(iTemp3 * iSlow154)) + fSlow155;
			float fTemp232 = fRec169[0] + -1.49999f;
			float fTemp233 = std::floor(fTemp232);
			float fTemp234 = fRec169[0] - fTemp233;
			float fTemp235 = fTemp233 + (2.0f - fRec169[0]);
			float fTemp236 = 0.7602446f * fRec161[1] + 0.6496369f * fTemp219;
			float fTemp237 = 0.7602446f * fTemp236;
			float fTemp238 = 0.6496369f * fRec167[1];
			float fTemp239 = 0.7602446f * fTemp231 - 0.6496369f * fRec166[1];
			fVec93[IOTA0 & 16383] = fTemp239 + (fTemp238 - fTemp237);
			float fTemp240 = fVec93[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp232)))) & 16383];
			fVec94[0] = fTemp240;
			fRec168[0] = 0.70710677f * (fTemp235 * fTemp240 / fTemp234 + fVec94[1]) - fRec168[1] * fTemp235 / fTemp234;
			fRec166[0] = fRec168[0];
			fRec171[0] = 0.9999f * (fRec171[1] + static_cast<float>(iTemp3 * iSlow156)) + fSlow157;
			float fTemp241 = fRec171[0] + -1.49999f;
			float fTemp242 = std::floor(fTemp241);
			float fTemp243 = fRec171[0] - fTemp242;
			float fTemp244 = fTemp242 + (2.0f - fRec171[0]);
			fVec95[IOTA0 & 16383] = fTemp239 + (fTemp237 - fTemp238);
			int iTemp245 = std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp241)));
			float fTemp246 = fVec95[(IOTA0 - iTemp245) & 16383];
			fVec96[0] = fTemp246;
			fRec170[0] = 0.70710677f * (fTemp244 * fTemp246 / fTemp243 + fVec96[1]) - fRec170[1] * fTemp244 / fTemp243;
			fRec167[0] = fRec170[0];
			float fTemp247 = 0.7602446f * fRec166[1] + 0.6496369f * fTemp231;
			fVec97[IOTA0 & 16383] = fTemp247;
			float fTemp248 = fSlow135 * (fRec138[0] + 1.0f);
			float fTemp249 = fTemp248 + 3.500005f;
			int iTemp250 = static_cast<int>(fTemp249);
			int iTemp251 = std::max<int>(0, iTemp250 + 4);
			float fTemp252 = std::floor(fTemp249);
			float fTemp253 = fTemp248 + (2.0f - fTemp252);
			float fTemp254 = fTemp248 + (3.0f - fTemp252);
			float fTemp255 = fTemp248 + (4.0f - fTemp252);
			float fTemp256 = fTemp248 + (5.0f - fTemp252);
			float fTemp257 = fTemp256 * fTemp255;
			float fTemp258 = fTemp257 * fTemp254;
			float fTemp259 = fTemp258 * fTemp253;
			int iTemp260 = std::max<int>(0, iTemp250 + 3);
			int iTemp261 = std::max<int>(0, iTemp250 + 2);
			int iTemp262 = std::max<int>(0, iTemp250 + 1);
			int iTemp263 = std::max<int>(0, iTemp250);
			float fTemp264 = fTemp248 + (1.0f - fTemp252);
			fVec98[IOTA0 & 16383] = fTemp264 * (fTemp253 * (fTemp254 * (0.041666668f * fVec97[(IOTA0 - std::min<int>(8192, iTemp263)) & 16383] * fTemp255 - 0.16666667f * fTemp256 * fVec97[(IOTA0 - std::min<int>(8192, iTemp262)) & 16383]) + 0.25f * fTemp257 * fVec97[(IOTA0 - std::min<int>(8192, iTemp261)) & 16383]) - 0.16666667f * fTemp258 * fVec97[(IOTA0 - std::min<int>(8192, iTemp260)) & 16383]) + 0.041666668f * fTemp259 * fVec97[(IOTA0 - std::min<int>(8192, iTemp251)) & 16383];
			float fTemp265 = fVec98[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp57)))) & 16383];
			fVec99[0] = fTemp265;
			fRec104[0] = fVec99[1] - (fTemp58 + (2.0f - fRec105[0])) * (fRec104[1] - fTemp265) / (fRec105[0] - fTemp58);
			fRec103[0] = -(fConst115 * (fConst114 * fRec103[1] - (fRec104[0] + fRec104[1])));
			fRec102[0] = fRec103[0] - fConst110 * (fConst108 * fRec102[2] + fConst103 * fRec102[1]);
			fRec101[0] = fConst110 * (fRec102[2] + fRec102[0] + 2.0f * fRec102[1]) - fConst107 * (fConst105 * fRec101[2] + fConst103 * fRec101[1]);
			float fTemp266 = fRec101[2] + fRec101[0] + 2.0f * fRec101[1];
			fVec100[0] = fTemp266;
			fRec100[0] = -(fConst118 * (fConst117 * fRec100[1] - fConst116 * (fTemp266 - fVec100[1])));
			fRec99[0] = fRec100[0] - fConst100 * (fConst98 * fRec99[2] + fConst94 * fRec99[1]);
			fRec98[0] = fConst119 * (fRec99[2] + (fRec99[0] - 2.0f * fRec99[1])) - fConst97 * (fConst96 * fRec98[2] + fConst94 * fRec98[1]);
			fRec174[0] = -(fConst118 * (fConst117 * fRec174[1] - fConst107 * (fTemp266 + fVec100[1])));
			fRec173[0] = fRec174[0] - fConst100 * (fConst98 * fRec173[2] + fConst94 * fRec173[1]);
			fRec172[0] = fConst100 * (fRec173[2] + fRec173[0] + 2.0f * fRec173[1]) - fConst97 * (fConst96 * fRec172[2] + fConst94 * fRec172[1]);
			float fTemp267 = fConst94 * fRec175[1];
			fRec178[0] = -(fConst115 * (fConst114 * fRec178[1] - fConst104 * (fRec104[0] - fRec104[1])));
			fRec177[0] = fRec178[0] - fConst110 * (fConst108 * fRec177[2] + fConst103 * fRec177[1]);
			fRec176[0] = fConst122 * (fRec177[2] + (fRec177[0] - 2.0f * fRec177[1])) - fConst107 * (fConst105 * fRec176[2] + fConst103 * fRec176[1]);
			fRec175[0] = fConst123 * (fRec176[2] + (fRec176[0] - 2.0f * fRec176[1])) - fConst121 * (fConst120 * fRec175[2] + fTemp267);
			float fTemp268 = fTemp18 + fSlow158 * (0.7f * (fRec175[2] + fConst121 * (fTemp267 + fConst120 * fRec175[0])) + fConst97 * (fRec172[2] + fRec172[0] + 2.0f * fRec172[1] + fConst93 * (fRec98[2] + (fRec98[0] - 2.0f * fRec98[1]))));
			fVec101[IOTA0 & 1023] = fTemp268;
			fRec97[0] = fSlow106 * (fTemp264 * (fTemp253 * (fTemp254 * (0.041666668f * fTemp255 * fVec101[(IOTA0 - std::min<int>(512, iTemp263)) & 1023] - 0.16666667f * fTemp256 * fVec101[(IOTA0 - std::min<int>(512, iTemp262)) & 1023]) + 0.25f * fTemp257 * fVec101[(IOTA0 - std::min<int>(512, iTemp261)) & 1023]) - 0.16666667f * fTemp258 * fVec101[(IOTA0 - std::min<int>(512, iTemp260)) & 1023]) + 0.041666668f * fTemp259 * fVec101[(IOTA0 - std::min<int>(512, iTemp251)) & 1023]) + fSlow4 * fRec97[1];
			fRec190[0] = 0.995f * (fRec190[1] + static_cast<float>(iTemp3 * iSlow159)) + fSlow160;
			float fTemp269 = fRec190[0] + -1.49999f;
			float fTemp270 = std::floor(fTemp269);
			float fTemp271 = 0.7602446f * fRec167[1] + 0.6496369f * fTemp236;
			fVec102[IOTA0 & 16383] = fTemp271;
			float fTemp272 = fSlow135 * (1.0f - fRec138[0]);
			float fTemp273 = fTemp272 + 3.500005f;
			int iTemp274 = static_cast<int>(fTemp273);
			float fTemp275 = std::floor(fTemp273);
			float fTemp276 = fTemp272 + (2.0f - fTemp275);
			float fTemp277 = fTemp272 + (3.0f - fTemp275);
			float fTemp278 = fTemp272 + (4.0f - fTemp275);
			float fTemp279 = fTemp272 + (5.0f - fTemp275);
			float fTemp280 = fTemp279 * fTemp278;
			float fTemp281 = fTemp280 * fTemp277;
			fVec103[IOTA0 & 16383] = (fTemp272 + (1.0f - fTemp275)) * (fTemp276 * (fTemp277 * (0.041666668f * fVec102[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp274))) & 16383] * fTemp278 - 0.16666667f * fTemp279 * fVec102[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp274 + 1))) & 16383]) + 0.25f * fTemp280 * fVec102[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp274 + 2))) & 16383]) - 0.16666667f * fTemp281 * fVec102[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp274 + 3))) & 16383]) + 0.041666668f * fTemp281 * fTemp276 * fVec102[(IOTA0 - std::min<int>(8192, std::max<int>(0, iTemp274 + 4))) & 16383];
			float fTemp282 = fVec103[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp269)))) & 16383];
			fVec104[0] = fTemp282;
			fRec189[0] = fVec104[1] - (fTemp270 + (2.0f - fRec190[0])) * (fRec189[1] - fTemp282) / (fRec190[0] - fTemp270);
			fRec188[0] = -(fConst115 * (fConst114 * fRec188[1] - (fRec189[0] + fRec189[1])));
			fRec187[0] = fRec188[0] - fConst110 * (fConst108 * fRec187[2] + fConst103 * fRec187[1]);
			fRec186[0] = fConst110 * (fRec187[2] + fRec187[0] + 2.0f * fRec187[1]) - fConst107 * (fConst105 * fRec186[2] + fConst103 * fRec186[1]);
			float fTemp283 = fRec186[2] + fRec186[0] + 2.0f * fRec186[1];
			fVec105[0] = fTemp283;
			fRec185[0] = -(fConst118 * (fConst117 * fRec185[1] - fConst116 * (fTemp283 - fVec105[1])));
			fRec184[0] = fRec185[0] - fConst100 * (fConst98 * fRec184[2] + fConst94 * fRec184[1]);
			fRec183[0] = fConst119 * (fRec184[2] + (fRec184[0] - 2.0f * fRec184[1])) - fConst97 * (fConst96 * fRec183[2] + fConst94 * fRec183[1]);
			fRec193[0] = -(fConst118 * (fConst117 * fRec193[1] - fConst107 * (fTemp283 + fVec105[1])));
			fRec192[0] = fRec193[0] - fConst100 * (fConst98 * fRec192[2] + fConst94 * fRec192[1]);
			fRec191[0] = fConst100 * (fRec192[2] + fRec192[0] + 2.0f * fRec192[1]) - fConst97 * (fConst96 * fRec191[2] + fConst94 * fRec191[1]);
			float fTemp284 = fConst94 * fRec194[1];
			fRec197[0] = -(fConst115 * (fConst114 * fRec197[1] - fConst104 * (fRec189[0] - fRec189[1])));
			fRec196[0] = fRec197[0] - fConst110 * (fConst108 * fRec196[2] + fConst103 * fRec196[1]);
			fRec195[0] = fConst122 * (fRec196[2] + (fRec196[0] - 2.0f * fRec196[1])) - fConst107 * (fConst105 * fRec195[2] + fConst103 * fRec195[1]);
			fRec194[0] = fConst123 * (fRec195[2] + (fRec195[0] - 2.0f * fRec195[1])) - fConst121 * (fConst120 * fRec194[2] + fTemp284);
			float fTemp285 = fSlow30 * fTemp30 + fSlow29 * fTemp31;
			float fTemp286 = fTemp285 + fSlow158 * (0.7f * (fRec194[2] + fConst121 * (fTemp284 + fConst120 * fRec194[0])) + fConst97 * (fRec191[2] + fRec191[0] + 2.0f * fRec191[1] + fConst93 * (fRec183[2] + (fRec183[0] - 2.0f * fRec183[1]))));
			fVec106[IOTA0 & 1023] = fTemp286;
			fRec182[0] = fSlow106 * (fTemp153 * (fTemp142 * (fTemp143 * (0.041666668f * fTemp144 * fVec106[(IOTA0 - iTemp152) & 1023] - 0.16666667f * fTemp145 * fVec106[(IOTA0 - iTemp151) & 1023]) + 0.25f * fTemp146 * fVec106[(IOTA0 - iTemp150) & 1023]) - 0.16666667f * fTemp147 * fVec106[(IOTA0 - iTemp149) & 1023]) + 0.041666668f * fTemp148 * fVec106[(IOTA0 - iTemp140) & 1023]) + fSlow4 * fRec182[1];
			float fTemp287 = 0.760314f * fRec182[0];
			float fTemp288 = 0.64955574f * fRec180[1];
			float fTemp289 = 0.760314f * fRec97[0] - 0.64955574f * fRec179[1];
			fVec107[IOTA0 & 16383] = fTemp289 + (fTemp288 - fTemp287);
			float fTemp290 = fVec107[(IOTA0 - iTemp196) & 16383];
			fVec108[0] = fTemp290;
			fRec181[0] = 0.70710677f * (fTemp195 * fTemp290 / fTemp194 + fVec108[1]) - fRec181[1] * fTemp195 / fTemp194;
			fRec179[0] = fRec181[0];
			fRec199[0] = 0.9999f * (fRec199[1] + static_cast<float>(iTemp3 * iSlow161)) + fSlow162;
			float fTemp291 = fRec199[0] + -1.49999f;
			float fTemp292 = std::floor(fTemp291);
			float fTemp293 = fRec199[0] - fTemp292;
			float fTemp294 = fTemp292 + (2.0f - fRec199[0]);
			fVec109[IOTA0 & 16383] = fTemp289 + (fTemp287 - fTemp288);
			float fTemp295 = fVec109[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp291)))) & 16383];
			fVec110[0] = fTemp295;
			fRec198[0] = 0.70710677f * (fTemp294 * fTemp295 / fTemp293 + fVec110[1]) - fRec198[1] * fTemp294 / fTemp293;
			fRec180[0] = fRec198[0];
			float fTemp296 = 0.760314f * fRec179[1] + 0.64955574f * fRec97[0];
			float fTemp297 = 0.760314f * fRec180[1] + 0.64955574f * fRec182[0];
			float fTemp298 = 0.760314f * fTemp297;
			float fTemp299 = 0.64955574f * fRec201[1];
			float fTemp300 = 0.760314f * fTemp296 - 0.64955574f * fRec200[1];
			fVec111[IOTA0 & 16383] = fTemp300 + (fTemp299 - fTemp298);
			float fTemp301 = fVec111[(IOTA0 - iTemp223) & 16383];
			fVec112[0] = fTemp301;
			fRec202[0] = 0.70710677f * (fTemp218 * fTemp301 / fTemp217 + fVec112[1]) - fRec202[1] * fTemp218 / fTemp217;
			fRec200[0] = fRec202[0];
			fVec113[IOTA0 & 16383] = fTemp300 + (fTemp298 - fTemp299);
			float fTemp302 = fVec113[(IOTA0 - iTemp212) & 16383];
			fVec114[0] = fTemp302;
			fRec203[0] = 0.70710677f * (fTemp211 * fTemp302 / fTemp210 + fVec114[1]) - fTemp211 * fRec203[1] / fTemp210;
			fRec201[0] = fRec203[0];
			float fTemp303 = 0.760314f * fRec200[1] + 0.64955574f * fTemp296;
			float fTemp304 = 0.760314f * fRec201[1] + 0.64955574f * fTemp297;
			float fTemp305 = 0.760314f * fTemp304;
			float fTemp306 = 0.64955574f * fRec205[1];
			float fTemp307 = 0.760314f * fTemp303 - 0.64955574f * fRec204[1];
			fVec115[IOTA0 & 16383] = fTemp307 + (fTemp306 - fTemp305);
			float fTemp308 = fVec115[(IOTA0 - iTemp229) & 16383];
			fVec116[0] = fTemp308;
			fRec206[0] = 0.70710677f * (fTemp228 * fTemp308 / fTemp227 + fVec116[1]) - fRec206[1] * fTemp228 / fTemp227;
			fRec204[0] = fRec206[0];
			fRec208[0] = 0.9999f * (fRec208[1] + static_cast<float>(iTemp3 * iSlow163)) + fSlow164;
			float fTemp309 = fRec208[0] + -1.49999f;
			float fTemp310 = std::floor(fTemp309);
			float fTemp311 = fRec208[0] - fTemp310;
			float fTemp312 = fTemp310 + (2.0f - fRec208[0]);
			fVec117[IOTA0 & 16383] = fTemp307 + (fTemp305 - fTemp306);
			float fTemp313 = fVec117[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp309)))) & 16383];
			fVec118[0] = fTemp313;
			fRec207[0] = 0.70710677f * (fTemp312 * fTemp313 / fTemp311 + fVec118[1]) - fRec207[1] * fTemp312 / fTemp311;
			fRec205[0] = fRec207[0];
			float fTemp314 = 0.760314f * fRec204[1] + 0.64955574f * fTemp303;
			fRec212[0] = 0.9999f * (fRec212[1] + static_cast<float>(iTemp3 * iSlow165)) + fSlow166;
			float fTemp315 = fRec212[0] + -1.49999f;
			float fTemp316 = std::floor(fTemp315);
			float fTemp317 = fRec212[0] - fTemp316;
			float fTemp318 = fTemp316 + (2.0f - fRec212[0]);
			float fTemp319 = 0.760314f * fRec205[1] + 0.64955574f * fTemp304;
			float fTemp320 = 0.760314f * fTemp319;
			float fTemp321 = 0.64955574f * fRec210[1];
			float fTemp322 = 0.760314f * fTemp314 - 0.64955574f * fRec209[1];
			fVec119[IOTA0 & 16383] = fTemp322 + (fTemp321 - fTemp320);
			float fTemp323 = fVec119[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp315)))) & 16383];
			fVec120[0] = fTemp323;
			fRec211[0] = 0.70710677f * (fTemp318 * fTemp323 / fTemp317 + fVec120[1]) - fRec211[1] * fTemp318 / fTemp317;
			fRec209[0] = fRec211[0];
			fVec121[IOTA0 & 16383] = fTemp322 + (fTemp320 - fTemp321);
			float fTemp324 = fVec121[(IOTA0 - iTemp245) & 16383];
			fVec122[0] = fTemp324;
			fRec213[0] = 0.70710677f * (fTemp244 * fTemp324 / fTemp243 + fVec122[1]) - fTemp244 * fRec213[1] / fTemp243;
			fRec210[0] = fRec213[0];
			fRec95[0] = 0.760314f * fRec209[1] + 0.64955574f * fTemp314;
			fRec96[0] = 0.760314f * fRec210[1] + 0.64955574f * fTemp319;
			float fTemp325 = fSlow4 + fVec2[1];
			fVec123[0] = fSlow168;
			float fTemp326 = fSlow167 + fVec123[1] + 0.3f;
			float fTemp327 = fConst1 * static_cast<float>(iVec0[1] + 2);
			float fTemp328 = std::cos(fTemp327);
			float fTemp329 = std::sin(fTemp327);
			fRec217[0] = fRec218[1] * fTemp329 + fRec217[1] * fTemp328;
			fRec218[0] = fTemp136 + fRec218[1] * fTemp328 - fTemp329 * fRec217[1];
			float fTemp330 = fSlow134 + fVec71[1];
			float fTemp331 = fConst124 * fTemp330 * (fRec218[0] + 1.0f);
			float fTemp332 = fTemp331 + 8.500005f;
			int iTemp333 = static_cast<int>(fTemp332);
			float fTemp334 = std::floor(fTemp332);
			float fTemp335 = fTemp331 + (7.0f - fTemp334);
			float fTemp336 = fTemp331 + (8.0f - fTemp334);
			float fTemp337 = fTemp331 + (9.0f - fTemp334);
			float fTemp338 = fTemp331 + (1e+01f - fTemp334);
			float fTemp339 = fTemp338 * fTemp337;
			float fTemp340 = fTemp339 * fTemp336;
			float fTemp341 = (fTemp331 + (6.0f - fTemp334)) * (fTemp335 * (fTemp336 * (0.041666668f * fRec214[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp333)) + 1)) & 1023] * fTemp337 - 0.16666667f * fTemp338 * fRec214[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp333 + 1)) + 1)) & 1023]) + 0.25f * fTemp339 * fRec214[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp333 + 2)) + 1)) & 1023]) - 0.16666667f * fTemp340 * fRec214[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp333 + 3)) + 1)) & 1023]) + 0.041666668f * fTemp340 * fTemp335 * fRec214[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp333 + 4)) + 1)) & 1023];
			fVec124[IOTA0 & 131071] = fTemp341;
			float fTemp342 = ((fRec219[1] != 0.0f) ? (((fRec220[1] > 0.0f) & (fRec220[1] < 1.0f)) ? fRec219[1] : 0.0f) : (((fRec220[1] == 0.0f) & (fSlow169 != fRec221[1])) ? 4.5351473e-05f : (((fRec220[1] == 1.0f) & (fSlow169 != fRec222[1])) ? -4.5351473e-05f : 0.0f)));
			fRec219[0] = fTemp342;
			fRec220[0] = std::max<float>(0.0f, std::min<float>(1.0f, fRec220[1] + fTemp342));
			fRec221[0] = (((fRec220[1] >= 1.0f) & (fRec222[1] != fSlow169)) ? fSlow169 : fRec221[1]);
			fRec222[0] = (((fRec220[1] <= 0.0f) & (fRec221[1] != fSlow169)) ? fSlow169 : fRec222[1]);
			int iTemp343 = static_cast<int>(std::min<float>(65536.0f, std::max<float>(0.0f, fRec221[0])));
			float fTemp344 = fVec124[(IOTA0 - iTemp343) & 131071];
			int iTemp345 = static_cast<int>(std::min<float>(65536.0f, std::max<float>(0.0f, fRec222[0])));
			float fTemp346 = fTemp18 + 0.5f * (fTemp344 + fRec220[0] * (fVec124[(IOTA0 - iTemp345) & 131071] - fTemp344)) * fTemp326;
			float fTemp347 = fVec3[1] + 0.5f;
			float fTemp348 = 0.5f * fTemp347;
			float fTemp349 = std::sin(fTemp348);
			float fTemp350 = std::cos(fTemp348);
			float fTemp351 = fConst124 * fTemp330 * (fRec217[0] + 1.0f);
			float fTemp352 = fTemp351 + 8.500005f;
			int iTemp353 = static_cast<int>(fTemp352);
			float fTemp354 = std::floor(fTemp352);
			float fTemp355 = fTemp351 + (7.0f - fTemp354);
			float fTemp356 = fTemp351 + (8.0f - fTemp354);
			float fTemp357 = fTemp351 + (9.0f - fTemp354);
			float fTemp358 = fTemp351 + (1e+01f - fTemp354);
			float fTemp359 = fTemp358 * fTemp357;
			float fTemp360 = fTemp359 * fTemp356;
			float fTemp361 = (fTemp351 + (6.0f - fTemp354)) * (fTemp355 * (fTemp356 * (0.041666668f * fRec215[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp353)) + 1)) & 1023] * fTemp357 - 0.16666667f * fTemp358 * fRec215[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp353 + 1)) + 1)) & 1023]) + 0.25f * fTemp359 * fRec215[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp353 + 2)) + 1)) & 1023]) - 0.16666667f * fTemp360 * fRec215[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp353 + 3)) + 1)) & 1023]) + 0.041666668f * fTemp360 * fTemp355 * fRec215[(IOTA0 - (std::min<int>(512, std::max<int>(0, iTemp353 + 4)) + 1)) & 1023];
			fVec125[IOTA0 & 131071] = fTemp361;
			float fTemp362 = fVec125[(IOTA0 - iTemp343) & 131071];
			float fTemp363 = fTemp285 + 0.5f * fTemp326 * (fTemp362 + fRec220[0] * (fVec125[(IOTA0 - iTemp345) & 131071] - fTemp362));
			float fTemp364 = fTemp350 * fTemp363 - fTemp349 * fRec224[1];
			float fTemp365 = fTemp350 * fTemp364 - fTemp349 * fRec227[1];
			float fTemp366 = fTemp350 * fTemp365 - fTemp349 * fRec230[1];
			fRec235[0] = 0.9999f * (fRec235[1] + static_cast<float>(iTemp3 * iSlow170)) + fSlow171;
			float fTemp367 = fRec235[0] + -1.49999f;
			float fTemp368 = std::floor(fTemp367);
			fVec126[IOTA0 & 16383] = fTemp349 * fRec233[1] - fTemp350 * fTemp366;
			float fTemp369 = fVec126[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp367)))) & 16383];
			fVec127[0] = fTemp369;
			fRec234[0] = fVec127[1] - (fTemp368 + (2.0f - fRec235[0])) * (fRec234[1] - fTemp369) / (fRec235[0] - fTemp368);
			fRec232[0] = fRec234[0];
			fRec237[0] = 0.9999f * (fRec237[1] + static_cast<float>(iTemp3 * iSlow172)) + fSlow173;
			float fTemp370 = fRec237[0] + -1.49999f;
			float fTemp371 = std::floor(fTemp370);
			float fTemp372 = fTemp346 * fTemp350 - fTemp349 * fRec223[1];
			float fTemp373 = fTemp350 * fTemp372 - fTemp349 * fRec226[1];
			float fTemp374 = fTemp350 * fTemp373 - fTemp349 * fRec229[1];
			fVec128[IOTA0 & 16383] = fTemp350 * fTemp374 - fTemp349 * fRec232[1];
			float fTemp375 = fVec128[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp370)))) & 16383];
			fVec129[0] = fTemp375;
			fRec236[0] = fVec129[1] - (fTemp371 + (2.0f - fRec237[0])) * (fRec236[1] - fTemp375) / (fRec237[0] - fTemp371);
			fRec233[0] = fRec236[0];
			fVec130[IOTA0 & 16383] = fTemp350 * fRec233[1] + fTemp349 * fTemp366;
			fRec238[0] = 0.9999f * (fRec238[1] + static_cast<float>(iTemp3 * iSlow174)) + fSlow175;
			float fTemp376 = fRec238[0] + -1.49999f;
			float fTemp377 = fVec130[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp376)))) & 16383];
			fVec131[0] = fTemp377;
			float fTemp378 = std::floor(fTemp376);
			float fTemp379 = fRec238[0] - fTemp378;
			float fTemp380 = fTemp378 + (2.0f - fRec238[0]);
			fRec231[0] = -(fRec231[1] * fTemp380 / fTemp379 + fTemp380 * fTemp377 / fTemp379 + fVec131[1]);
			fRec229[0] = fRec231[0];
			fRec240[0] = 0.9999f * (fRec240[1] + static_cast<float>(iTemp3 * iSlow176)) + fSlow177;
			float fTemp381 = fRec240[0] + -1.49999f;
			float fTemp382 = std::floor(fTemp381);
			fVec132[IOTA0 & 16383] = fRec232[1] * fTemp350 + fTemp349 * fTemp374;
			float fTemp383 = fVec132[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp381)))) & 16383];
			fVec133[0] = fTemp383;
			fRec239[0] = fVec133[1] - (fTemp382 + (2.0f - fRec240[0])) * (fRec239[1] - fTemp383) / (fRec240[0] - fTemp382);
			fRec230[0] = fRec239[0];
			fVec134[IOTA0 & 16383] = fTemp350 * fRec230[1] + fTemp349 * fTemp365;
			fRec241[0] = 0.9999f * (fRec241[1] + static_cast<float>(iTemp3 * iSlow178)) + fSlow179;
			float fTemp384 = fRec241[0] + -1.49999f;
			float fTemp385 = fVec134[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp384)))) & 16383];
			fVec135[0] = fTemp385;
			float fTemp386 = std::floor(fTemp384);
			float fTemp387 = fRec241[0] - fTemp386;
			float fTemp388 = fTemp386 + (2.0f - fRec241[0]);
			fRec228[0] = -(fRec228[1] * fTemp388 / fTemp387 + fTemp388 * fTemp385 / fTemp387 + fVec135[1]);
			fRec226[0] = fRec228[0];
			fRec243[0] = 0.9999f * (fRec243[1] + static_cast<float>(iTemp3 * iSlow180)) + fSlow181;
			float fTemp389 = fRec243[0] + -1.49999f;
			float fTemp390 = std::floor(fTemp389);
			fVec136[IOTA0 & 16383] = fRec229[1] * fTemp350 + fTemp349 * fTemp373;
			float fTemp391 = fVec136[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp389)))) & 16383];
			fVec137[0] = fTemp391;
			fRec242[0] = fVec137[1] - (fTemp390 + (2.0f - fRec243[0])) * (fRec242[1] - fTemp391) / (fRec243[0] - fTemp390);
			fRec227[0] = fRec242[0];
			fVec138[IOTA0 & 16383] = fTemp350 * fRec227[1] + fTemp349 * fTemp364;
			float fTemp392 = fVec138[(IOTA0 - iTemp68) & 16383];
			fVec139[0] = fTemp392;
			fRec225[0] = -(fTemp64 * fRec225[1] / fTemp63 + fTemp64 * fTemp392 / fTemp63 + fVec139[1]);
			fRec223[0] = fRec225[0];
			fRec245[0] = 0.9999f * (fRec245[1] + static_cast<float>(iTemp3 * iSlow182)) + fSlow183;
			float fTemp393 = fRec245[0] + -1.49999f;
			float fTemp394 = std::floor(fTemp393);
			fVec140[IOTA0 & 16383] = fRec226[1] * fTemp350 + fTemp349 * fTemp372;
			float fTemp395 = fVec140[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp393)))) & 16383];
			fVec141[0] = fTemp395;
			fRec244[0] = fVec141[1] - (fTemp394 + (2.0f - fRec245[0])) * (fRec244[1] - fTemp395) / (fRec245[0] - fTemp394);
			fRec224[0] = fRec244[0];
			float fTemp396 = fRec223[1] * fTemp350 + fTemp349 * fTemp346;
			float fTemp397 = -0.5f * fTemp347;
			float fTemp398 = std::sin(fTemp397);
			float fTemp399 = std::cos(fTemp397);
			float fTemp400 = fTemp350 * fRec224[1] + fTemp349 * fTemp363;
			float fTemp401 = fTemp399 * fTemp400 - fTemp398 * fRec247[1];
			float fTemp402 = fTemp399 * fTemp401 - fTemp398 * fRec250[1];
			float fTemp403 = fTemp399 * fTemp402 - fTemp398 * fRec253[1];
			fRec258[0] = 0.9999f * (fRec258[1] + static_cast<float>(iTemp3 * iSlow184)) + fSlow185;
			float fTemp404 = fRec258[0] + -1.49999f;
			float fTemp405 = std::floor(fTemp404);
			fVec142[IOTA0 & 16383] = fTemp398 * fRec256[1] - fTemp399 * fTemp403;
			float fTemp406 = fVec142[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp404)))) & 16383];
			fVec143[0] = fTemp406;
			fRec257[0] = fVec143[1] - (fTemp405 + (2.0f - fRec258[0])) * (fRec257[1] - fTemp406) / (fRec258[0] - fTemp405);
			fRec255[0] = fRec257[0];
			fRec260[0] = 0.9999f * (fRec260[1] + static_cast<float>(iTemp3 * iSlow186)) + fSlow187;
			float fTemp407 = fRec260[0] + -1.49999f;
			float fTemp408 = std::floor(fTemp407);
			float fTemp409 = fTemp396 * fTemp399 - fTemp398 * fRec246[1];
			float fTemp410 = fTemp399 * fTemp409 - fTemp398 * fRec249[1];
			float fTemp411 = fTemp399 * fTemp410 - fTemp398 * fRec252[1];
			fVec144[IOTA0 & 16383] = fTemp399 * fTemp411 - fRec255[1] * fTemp398;
			float fTemp412 = fVec144[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp407)))) & 16383];
			fVec145[0] = fTemp412;
			fRec259[0] = fVec145[1] - (fTemp408 + (2.0f - fRec260[0])) * (fRec259[1] - fTemp412) / (fRec260[0] - fTemp408);
			fRec256[0] = fRec259[0];
			fVec146[IOTA0 & 16383] = fTemp399 * fRec256[1] + fTemp398 * fTemp403;
			float fTemp413 = fVec146[(IOTA0 - iTemp196) & 16383];
			fVec147[0] = fTemp413;
			fRec254[0] = -(fTemp195 * fRec254[1] / fTemp194 + fTemp195 * fTemp413 / fTemp194 + fVec147[1]);
			fRec252[0] = fRec254[0];
			fRec262[0] = 0.9999f * (fRec262[1] + static_cast<float>(iTemp3 * iSlow188)) + fSlow189;
			float fTemp414 = fRec262[0] + -1.49999f;
			float fTemp415 = std::floor(fTemp414);
			fVec148[IOTA0 & 16383] = fRec255[1] * fTemp399 + fTemp398 * fTemp411;
			float fTemp416 = fVec148[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp414)))) & 16383];
			fVec149[0] = fTemp416;
			fRec261[0] = fVec149[1] - (fTemp415 + (2.0f - fRec262[0])) * (fRec261[1] - fTemp416) / (fRec262[0] - fTemp415);
			fRec253[0] = fRec261[0];
			fVec150[IOTA0 & 16383] = fTemp399 * fRec253[1] + fTemp398 * fTemp402;
			fRec263[0] = 0.9999f * (fRec263[1] + static_cast<float>(iTemp3 * iSlow190)) + fSlow191;
			float fTemp417 = fRec263[0] + -1.49999f;
			float fTemp418 = fVec150[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp417)))) & 16383];
			fVec151[0] = fTemp418;
			float fTemp419 = std::floor(fTemp417);
			float fTemp420 = fRec263[0] - fTemp419;
			float fTemp421 = fTemp419 + (2.0f - fRec263[0]);
			fRec251[0] = -(fRec251[1] * fTemp421 / fTemp420 + fTemp421 * fTemp418 / fTemp420 + fVec151[1]);
			fRec249[0] = fRec251[0];
			fRec265[0] = 0.9999f * (fRec265[1] + static_cast<float>(iTemp3 * iSlow192)) + fSlow193;
			float fTemp422 = fRec265[0] + -1.49999f;
			float fTemp423 = std::floor(fTemp422);
			fVec152[IOTA0 & 16383] = fRec252[1] * fTemp399 + fTemp398 * fTemp410;
			float fTemp424 = fVec152[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp422)))) & 16383];
			fVec153[0] = fTemp424;
			fRec264[0] = fVec153[1] - (fTemp423 + (2.0f - fRec265[0])) * (fRec264[1] - fTemp424) / (fRec265[0] - fTemp423);
			fRec250[0] = fRec264[0];
			fVec154[IOTA0 & 16383] = fTemp399 * fRec250[1] + fTemp398 * fTemp401;
			fRec266[0] = 0.9999f * (fRec266[1] + static_cast<float>(iTemp3 * iSlow194)) + fSlow195;
			float fTemp425 = fRec266[0] + -1.49999f;
			float fTemp426 = fVec154[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp425)))) & 16383];
			fVec155[0] = fTemp426;
			float fTemp427 = std::floor(fTemp425);
			float fTemp428 = fRec266[0] - fTemp427;
			float fTemp429 = fTemp427 + (2.0f - fRec266[0]);
			fRec248[0] = -(fRec248[1] * fTemp429 / fTemp428 + fTemp429 * fTemp426 / fTemp428 + fVec155[1]);
			fRec246[0] = fRec248[0];
			fRec268[0] = 0.9999f * (fRec268[1] + static_cast<float>(iTemp3 * iSlow196)) + fSlow197;
			float fTemp430 = fRec268[0] + -1.49999f;
			float fTemp431 = std::floor(fTemp430);
			fVec156[IOTA0 & 16383] = fRec249[1] * fTemp399 + fTemp398 * fTemp409;
			float fTemp432 = fVec156[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp430)))) & 16383];
			fVec157[0] = fTemp432;
			fRec267[0] = fVec157[1] - (fTemp431 + (2.0f - fRec268[0])) * (fRec267[1] - fTemp432) / (fRec268[0] - fTemp431);
			fRec247[0] = fRec267[0];
			float fTemp433 = fRec246[1] * fTemp399 + fTemp398 * fTemp396;
			float fTemp434 = fTemp399 * fRec247[1] + fTemp398 * fTemp400;
			float fTemp435 = fTemp350 * fTemp434 - fTemp349 * fRec270[1];
			float fTemp436 = fTemp350 * fTemp435 - fTemp349 * fRec273[1];
			float fTemp437 = fTemp350 * fTemp436 - fTemp349 * fRec276[1];
			fRec281[0] = 0.9999f * (fRec281[1] + static_cast<float>(iTemp3 * iSlow198)) + fSlow199;
			float fTemp438 = fRec281[0] + -1.49999f;
			float fTemp439 = std::floor(fTemp438);
			fVec158[IOTA0 & 16383] = fTemp349 * fRec279[1] - fTemp350 * fTemp437;
			float fTemp440 = fVec158[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp438)))) & 16383];
			fVec159[0] = fTemp440;
			fRec280[0] = fVec159[1] - (fTemp439 + (2.0f - fRec281[0])) * (fRec280[1] - fTemp440) / (fRec281[0] - fTemp439);
			fRec278[0] = fRec280[0];
			fRec283[0] = 0.9999f * (fRec283[1] + static_cast<float>(iTemp3 * iSlow200)) + fSlow201;
			float fTemp441 = fRec283[0] + -1.49999f;
			float fTemp442 = std::floor(fTemp441);
			float fTemp443 = fTemp350 * fTemp433 - fTemp349 * fRec269[1];
			float fTemp444 = fTemp350 * fTemp443 - fTemp349 * fRec272[1];
			float fTemp445 = fTemp350 * fTemp444 - fTemp349 * fRec275[1];
			fVec160[IOTA0 & 16383] = fTemp350 * fTemp445 - fRec278[1] * fTemp349;
			float fTemp446 = fVec160[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp441)))) & 16383];
			fVec161[0] = fTemp446;
			fRec282[0] = fVec161[1] - (fTemp442 + (2.0f - fRec283[0])) * (fRec282[1] - fTemp446) / (fRec283[0] - fTemp442);
			fRec279[0] = fRec282[0];
			fVec162[IOTA0 & 16383] = fTemp350 * fRec279[1] + fTemp349 * fTemp437;
			fRec284[0] = 0.9999f * (fRec284[1] + static_cast<float>(iTemp3 * iSlow202)) + fSlow203;
			float fTemp447 = fRec284[0] + -1.49999f;
			float fTemp448 = fVec162[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp447)))) & 16383];
			fVec163[0] = fTemp448;
			float fTemp449 = std::floor(fTemp447);
			float fTemp450 = fRec284[0] - fTemp449;
			float fTemp451 = fTemp449 + (2.0f - fRec284[0]);
			fRec277[0] = -(fRec277[1] * fTemp451 / fTemp450 + fTemp451 * fTemp448 / fTemp450 + fVec163[1]);
			fRec275[0] = fRec277[0];
			fRec286[0] = 0.9999f * (fRec286[1] + static_cast<float>(iTemp3 * iSlow204)) + fSlow205;
			float fTemp452 = fRec286[0] + -1.49999f;
			float fTemp453 = std::floor(fTemp452);
			fVec164[IOTA0 & 16383] = fRec278[1] * fTemp350 + fTemp349 * fTemp445;
			float fTemp454 = fVec164[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp452)))) & 16383];
			fVec165[0] = fTemp454;
			fRec285[0] = fVec165[1] - (fTemp453 + (2.0f - fRec286[0])) * (fRec285[1] - fTemp454) / (fRec286[0] - fTemp453);
			fRec276[0] = fRec285[0];
			fVec166[IOTA0 & 16383] = fTemp350 * fRec276[1] + fTemp349 * fTemp436;
			fRec287[0] = 0.9999f * (fRec287[1] + static_cast<float>(iTemp3 * iSlow206)) + fSlow207;
			float fTemp455 = fRec287[0] + -1.49999f;
			float fTemp456 = fVec166[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp455)))) & 16383];
			fVec167[0] = fTemp456;
			float fTemp457 = std::floor(fTemp455);
			float fTemp458 = fRec287[0] - fTemp457;
			float fTemp459 = fTemp457 + (2.0f - fRec287[0]);
			fRec274[0] = -(fRec274[1] * fTemp459 / fTemp458 + fTemp459 * fTemp456 / fTemp458 + fVec167[1]);
			fRec272[0] = fRec274[0];
			fRec289[0] = 0.9999f * (fRec289[1] + static_cast<float>(iTemp3 * iSlow208)) + fSlow209;
			float fTemp460 = fRec289[0] + -1.49999f;
			float fTemp461 = std::floor(fTemp460);
			fVec168[IOTA0 & 16383] = fRec275[1] * fTemp350 + fTemp349 * fTemp444;
			float fTemp462 = fVec168[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp460)))) & 16383];
			fVec169[0] = fTemp462;
			fRec288[0] = fVec169[1] - (fTemp461 + (2.0f - fRec289[0])) * (fRec288[1] - fTemp462) / (fRec289[0] - fTemp461);
			fRec273[0] = fRec288[0];
			fVec170[IOTA0 & 16383] = fTemp350 * fRec273[1] + fTemp349 * fTemp435;
			fRec290[0] = 0.9999f * (fRec290[1] + static_cast<float>(iTemp3 * iSlow210)) + fSlow211;
			float fTemp463 = fRec290[0] + -1.49999f;
			float fTemp464 = fVec170[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp463)))) & 16383];
			fVec171[0] = fTemp464;
			float fTemp465 = std::floor(fTemp463);
			float fTemp466 = fRec290[0] - fTemp465;
			float fTemp467 = fTemp465 + (2.0f - fRec290[0]);
			fRec271[0] = -(fRec271[1] * fTemp467 / fTemp466 + fTemp467 * fTemp464 / fTemp466 + fVec171[1]);
			fRec269[0] = fRec271[0];
			fRec292[0] = 0.9999f * (fRec292[1] + static_cast<float>(iTemp3 * iSlow212)) + fSlow213;
			float fTemp468 = fRec292[0] + -1.49999f;
			float fTemp469 = std::floor(fTemp468);
			fVec172[IOTA0 & 16383] = fRec272[1] * fTemp350 + fTemp349 * fTemp443;
			float fTemp470 = fVec172[(IOTA0 - std::min<int>(8192, std::max<int>(0, static_cast<int>(fTemp468)))) & 16383];
			fVec173[0] = fTemp470;
			fRec291[0] = fVec173[1] - (fTemp469 + (2.0f - fRec292[0])) * (fRec291[1] - fTemp470) / (fRec292[0] - fTemp469);
			fRec270[0] = fRec291[0];
			float fTemp471 = 1.0f - 0.5f * fTemp325;
			fRec216[0] = fTemp471 * (fRec269[1] * fTemp350 + fTemp349 * fTemp433) + 0.5f * fTemp325 * fRec216[1];
			fRec214[IOTA0 & 1023] = fRec216[0];
			fRec293[0] = fTemp471 * (fTemp350 * fRec270[1] + fTemp349 * fTemp434) + 0.5f * fTemp325 * fRec293[1];
			fRec215[IOTA0 & 1023] = fRec293[0];
			output0[i0] = static_cast<FAUSTFLOAT>(tanhf(fSlow216 * (fSlow215 * fTemp18 + fSlow214 * ((iSlow1) ? ((iSlow108) ? fRec214[IOTA0 & 1023] : fRec95[0]) : ((iSlow2) ? fRec74[0] : ((iSlow3) ? 0.37f * (fRec31[0] + fRec32[0]) : fRec1 + fRec0[1]))))));
			fRec303[0] = 0.5f * (fRec303[1] + fRec302[1]);
			fVec174[IOTA0 & 8191] = fTemp285 + fSlow5 * fRec303[0];
			fRec302[0] = fVec174[(IOTA0 - iConst125) & 8191];
			fRec305[0] = 0.5f * (fRec305[1] + fRec304[1]);
			fVec175[IOTA0 & 8191] = fTemp285 + fSlow5 * fRec305[0];
			fRec304[0] = fVec175[(IOTA0 - iConst126) & 8191];
			fRec307[0] = 0.5f * (fRec307[1] + fRec306[1]);
			fVec176[IOTA0 & 8191] = fTemp285 + fSlow5 * fRec307[0];
			fRec306[0] = fVec176[(IOTA0 - iConst127) & 8191];
			fRec309[0] = 0.5f * (fRec309[1] + fRec308[1]);
			fVec177[IOTA0 & 8191] = fTemp285 + fSlow5 * fRec309[0];
			fRec308[0] = fVec177[(IOTA0 - iConst128) & 8191];
			fRec311[0] = 0.5f * (fRec311[1] + fRec310[1]);
			fVec178[IOTA0 & 8191] = fTemp285 + fSlow5 * fRec311[0];
			fRec310[0] = fVec178[(IOTA0 - iConst129) & 8191];
			fRec313[0] = 0.5f * (fRec313[1] + fRec312[1]);
			fVec179[IOTA0 & 8191] = fTemp285 + fSlow5 * fRec313[0];
			fRec312[0] = fVec179[(IOTA0 - iConst130) & 8191];
			fRec315[0] = 0.5f * (fRec315[1] + fRec314[1]);
			fVec180[IOTA0 & 8191] = fTemp285 + fSlow5 * fRec315[0];
			fRec314[0] = fVec180[(IOTA0 - iConst131) & 8191];
			fRec317[0] = 0.5f * (fRec317[1] + fRec316[1]);
			fVec181[IOTA0 & 8191] = fTemp285 + fSlow5 * fRec317[0];
			fRec316[0] = fVec181[(IOTA0 - iConst132) & 8191];
			float fTemp472 = fRec316[1] + fRec314[1] + fRec312[1] + fRec310[1] + fRec308[1] + fRec306[1] + fRec304[1] + fSlow4 * fRec300[1] + fRec302[1];
			fVec182[IOTA0 & 2047] = fTemp472;
			fRec300[0] = fVec182[(IOTA0 - iConst133) & 2047];
			float fRec301 = -(fSlow4 * fTemp472);
			float fTemp473 = fRec300[1] + fRec301 + fSlow4 * fRec298[1];
			fVec183[IOTA0 & 2047] = fTemp473;
			fRec298[0] = fVec183[(IOTA0 - iConst134) & 2047];
			float fRec299 = -(fSlow4 * fTemp473);
			float fTemp474 = fRec298[1] + fRec299 + fSlow4 * fRec296[1];
			fVec184[IOTA0 & 2047] = fTemp474;
			fRec296[0] = fVec184[(IOTA0 - iConst135) & 2047];
			float fRec297 = -(fSlow4 * fTemp474);
			float fTemp475 = fRec296[1] + fRec297 + fSlow4 * fRec294[1];
			fVec185[IOTA0 & 1023] = fTemp475;
			fRec294[0] = fVec185[(IOTA0 - iConst136) & 1023];
			float fRec295 = -(fSlow4 * fTemp475);
			output1[i0] = static_cast<FAUSTFLOAT>(tanhf(fSlow216 * (fSlow215 * fTemp285 + fSlow214 * ((iSlow1) ? ((iSlow108) ? fRec215[IOTA0 & 1023] : fRec96[0]) : ((iSlow2) ? fRec75[0] : ((iSlow3) ? 0.37f * (fRec31[0] - fRec32[0]) : fRec295 + fRec294[1]))))));
			iVec0[1] = iVec0[0];
			iVec1[1] = iVec1[0];
			fVec2[1] = fVec2[0];
			fVec3[1] = fVec3[0];
			fRec9[1] = fRec9[0];
			IOTA0 = IOTA0 + 1;
			fVec4[1] = fVec4[0];
			fRec11[1] = fRec11[0];
			fRec12[2] = fRec12[1];
			fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec8[1] = fRec8[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			fRec0[1] = fRec0[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fVec20[1] = fVec20[0];
			fRec43[1] = fRec43[0];
			fRec44[2] = fRec44[1];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec38[1] = fRec38[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec54[1] = fRec54[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec58[1] = fRec58[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fRec70[1] = fRec70[0];
			fRec30[2] = fRec30[1];
			fRec30[1] = fRec30[0];
			fRec31[2] = fRec31[1];
			fRec31[1] = fRec31[0];
			fRec32[2] = fRec32[1];
			fRec32[1] = fRec32[0];
			fRec33[2] = fRec33[1];
			fRec33[1] = fRec33[0];
			fRec34[2] = fRec34[1];
			fRec34[1] = fRec34[0];
			fRec35[2] = fRec35[1];
			fRec35[1] = fRec35[0];
			fRec36[2] = fRec36[1];
			fRec36[1] = fRec36[0];
			fRec37[2] = fRec37[1];
			fRec37[1] = fRec37[0];
			fRec79[1] = fRec79[0];
			fRec78[1] = fRec78[0];
			fRec76[1] = fRec76[0];
			fRec89[2] = fRec89[1];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec85[1] = fRec85[0];
			fRec83[1] = fRec83[0];
			fRec81[1] = fRec81[0];
			fRec74[1] = fRec74[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec90[1] = fRec90[0];
			fRec75[1] = fRec75[0];
			fRec105[1] = fRec105[0];
			fRec107[1] = fRec107[0];
			fRec111[1] = fRec111[0];
			fVec51[1] = fVec51[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec113[1] = fRec113[0];
			fVec53[1] = fVec53[0];
			fRec112[1] = fRec112[0];
			fRec109[1] = fRec109[0];
			fRec117[1] = fRec117[0];
			fVec55[1] = fVec55[0];
			fRec116[1] = fRec116[0];
			fRec114[1] = fRec114[0];
			fRec119[1] = fRec119[0];
			fVec57[1] = fVec57[0];
			fRec118[1] = fRec118[0];
			fRec115[1] = fRec115[0];
			fRec123[1] = fRec123[0];
			fVec59[1] = fVec59[0];
			fRec122[1] = fRec122[0];
			fRec120[1] = fRec120[0];
			fRec125[1] = fRec125[0];
			fVec61[1] = fVec61[0];
			fRec124[1] = fRec124[0];
			fRec121[1] = fRec121[0];
			fRec129[1] = fRec129[0];
			fVec63[1] = fVec63[0];
			fRec128[1] = fRec128[0];
			fRec126[1] = fRec126[0];
			fRec131[1] = fRec131[0];
			fVec65[1] = fVec65[0];
			fRec130[1] = fRec130[0];
			fRec127[1] = fRec127[0];
			fRec135[1] = fRec135[0];
			fVec67[1] = fVec67[0];
			fRec134[1] = fRec134[0];
			fRec132[1] = fRec132[0];
			fRec137[1] = fRec137[0];
			fVec69[1] = fVec69[0];
			fRec136[1] = fRec136[0];
			fRec133[1] = fRec133[0];
			fRec138[1] = fRec138[0];
			fRec139[1] = fRec139[0];
			fVec71[1] = fVec71[0];
			fVec73[1] = fVec73[0];
			fRec106[1] = fRec106[0];
			fRec143[1] = fRec143[0];
			fRec145[1] = fRec145[0];
			fVec76[1] = fVec76[0];
			fRec144[1] = fRec144[0];
			fVec78[1] = fVec78[0];
			fRec142[1] = fRec142[0];
			fRec140[1] = fRec140[0];
			fRec147[1] = fRec147[0];
			fVec80[1] = fVec80[0];
			fRec146[1] = fRec146[0];
			fRec141[1] = fRec141[0];
			fRec151[1] = fRec151[0];
			fVec82[1] = fVec82[0];
			fRec150[1] = fRec150[0];
			fRec148[1] = fRec148[0];
			fRec153[1] = fRec153[0];
			fVec84[1] = fVec84[0];
			fRec152[1] = fRec152[0];
			fRec149[1] = fRec149[0];
			fRec157[1] = fRec157[0];
			fVec86[1] = fVec86[0];
			fRec156[1] = fRec156[0];
			fRec154[1] = fRec154[0];
			fRec159[1] = fRec159[0];
			fVec88[1] = fVec88[0];
			fRec158[1] = fRec158[0];
			fRec155[1] = fRec155[0];
			fRec163[1] = fRec163[0];
			fVec90[1] = fVec90[0];
			fRec162[1] = fRec162[0];
			fRec160[1] = fRec160[0];
			fRec165[1] = fRec165[0];
			fVec92[1] = fVec92[0];
			fRec164[1] = fRec164[0];
			fRec161[1] = fRec161[0];
			fRec169[1] = fRec169[0];
			fVec94[1] = fVec94[0];
			fRec168[1] = fRec168[0];
			fRec166[1] = fRec166[0];
			fRec171[1] = fRec171[0];
			fVec96[1] = fVec96[0];
			fRec170[1] = fRec170[0];
			fRec167[1] = fRec167[0];
			fVec99[1] = fVec99[0];
			fRec104[1] = fRec104[0];
			fRec103[1] = fRec103[0];
			fRec102[2] = fRec102[1];
			fRec102[1] = fRec102[0];
			fRec101[2] = fRec101[1];
			fRec101[1] = fRec101[0];
			fVec100[1] = fVec100[0];
			fRec100[1] = fRec100[0];
			fRec99[2] = fRec99[1];
			fRec99[1] = fRec99[0];
			fRec98[2] = fRec98[1];
			fRec98[1] = fRec98[0];
			fRec174[1] = fRec174[0];
			fRec173[2] = fRec173[1];
			fRec173[1] = fRec173[0];
			fRec172[2] = fRec172[1];
			fRec172[1] = fRec172[0];
			fRec178[1] = fRec178[0];
			fRec177[2] = fRec177[1];
			fRec177[1] = fRec177[0];
			fRec176[2] = fRec176[1];
			fRec176[1] = fRec176[0];
			fRec175[2] = fRec175[1];
			fRec175[1] = fRec175[0];
			fRec97[1] = fRec97[0];
			fRec190[1] = fRec190[0];
			fVec104[1] = fVec104[0];
			fRec189[1] = fRec189[0];
			fRec188[1] = fRec188[0];
			fRec187[2] = fRec187[1];
			fRec187[1] = fRec187[0];
			fRec186[2] = fRec186[1];
			fRec186[1] = fRec186[0];
			fVec105[1] = fVec105[0];
			fRec185[1] = fRec185[0];
			fRec184[2] = fRec184[1];
			fRec184[1] = fRec184[0];
			fRec183[2] = fRec183[1];
			fRec183[1] = fRec183[0];
			fRec193[1] = fRec193[0];
			fRec192[2] = fRec192[1];
			fRec192[1] = fRec192[0];
			fRec191[2] = fRec191[1];
			fRec191[1] = fRec191[0];
			fRec197[1] = fRec197[0];
			fRec196[2] = fRec196[1];
			fRec196[1] = fRec196[0];
			fRec195[2] = fRec195[1];
			fRec195[1] = fRec195[0];
			fRec194[2] = fRec194[1];
			fRec194[1] = fRec194[0];
			fRec182[1] = fRec182[0];
			fVec108[1] = fVec108[0];
			fRec181[1] = fRec181[0];
			fRec179[1] = fRec179[0];
			fRec199[1] = fRec199[0];
			fVec110[1] = fVec110[0];
			fRec198[1] = fRec198[0];
			fRec180[1] = fRec180[0];
			fVec112[1] = fVec112[0];
			fRec202[1] = fRec202[0];
			fRec200[1] = fRec200[0];
			fVec114[1] = fVec114[0];
			fRec203[1] = fRec203[0];
			fRec201[1] = fRec201[0];
			fVec116[1] = fVec116[0];
			fRec206[1] = fRec206[0];
			fRec204[1] = fRec204[0];
			fRec208[1] = fRec208[0];
			fVec118[1] = fVec118[0];
			fRec207[1] = fRec207[0];
			fRec205[1] = fRec205[0];
			fRec212[1] = fRec212[0];
			fVec120[1] = fVec120[0];
			fRec211[1] = fRec211[0];
			fRec209[1] = fRec209[0];
			fVec122[1] = fVec122[0];
			fRec213[1] = fRec213[0];
			fRec210[1] = fRec210[0];
			fRec95[1] = fRec95[0];
			fRec96[1] = fRec96[0];
			fVec123[1] = fVec123[0];
			fRec217[1] = fRec217[0];
			fRec218[1] = fRec218[0];
			fRec219[1] = fRec219[0];
			fRec220[1] = fRec220[0];
			fRec221[1] = fRec221[0];
			fRec222[1] = fRec222[0];
			fRec235[1] = fRec235[0];
			fVec127[1] = fVec127[0];
			fRec234[1] = fRec234[0];
			fRec232[1] = fRec232[0];
			fRec237[1] = fRec237[0];
			fVec129[1] = fVec129[0];
			fRec236[1] = fRec236[0];
			fRec233[1] = fRec233[0];
			fRec238[1] = fRec238[0];
			fVec131[1] = fVec131[0];
			fRec231[1] = fRec231[0];
			fRec229[1] = fRec229[0];
			fRec240[1] = fRec240[0];
			fVec133[1] = fVec133[0];
			fRec239[1] = fRec239[0];
			fRec230[1] = fRec230[0];
			fRec241[1] = fRec241[0];
			fVec135[1] = fVec135[0];
			fRec228[1] = fRec228[0];
			fRec226[1] = fRec226[0];
			fRec243[1] = fRec243[0];
			fVec137[1] = fVec137[0];
			fRec242[1] = fRec242[0];
			fRec227[1] = fRec227[0];
			fVec139[1] = fVec139[0];
			fRec225[1] = fRec225[0];
			fRec223[1] = fRec223[0];
			fRec245[1] = fRec245[0];
			fVec141[1] = fVec141[0];
			fRec244[1] = fRec244[0];
			fRec224[1] = fRec224[0];
			fRec258[1] = fRec258[0];
			fVec143[1] = fVec143[0];
			fRec257[1] = fRec257[0];
			fRec255[1] = fRec255[0];
			fRec260[1] = fRec260[0];
			fVec145[1] = fVec145[0];
			fRec259[1] = fRec259[0];
			fRec256[1] = fRec256[0];
			fVec147[1] = fVec147[0];
			fRec254[1] = fRec254[0];
			fRec252[1] = fRec252[0];
			fRec262[1] = fRec262[0];
			fVec149[1] = fVec149[0];
			fRec261[1] = fRec261[0];
			fRec253[1] = fRec253[0];
			fRec263[1] = fRec263[0];
			fVec151[1] = fVec151[0];
			fRec251[1] = fRec251[0];
			fRec249[1] = fRec249[0];
			fRec265[1] = fRec265[0];
			fVec153[1] = fVec153[0];
			fRec264[1] = fRec264[0];
			fRec250[1] = fRec250[0];
			fRec266[1] = fRec266[0];
			fVec155[1] = fVec155[0];
			fRec248[1] = fRec248[0];
			fRec246[1] = fRec246[0];
			fRec268[1] = fRec268[0];
			fVec157[1] = fVec157[0];
			fRec267[1] = fRec267[0];
			fRec247[1] = fRec247[0];
			fRec281[1] = fRec281[0];
			fVec159[1] = fVec159[0];
			fRec280[1] = fRec280[0];
			fRec278[1] = fRec278[0];
			fRec283[1] = fRec283[0];
			fVec161[1] = fVec161[0];
			fRec282[1] = fRec282[0];
			fRec279[1] = fRec279[0];
			fRec284[1] = fRec284[0];
			fVec163[1] = fVec163[0];
			fRec277[1] = fRec277[0];
			fRec275[1] = fRec275[0];
			fRec286[1] = fRec286[0];
			fVec165[1] = fVec165[0];
			fRec285[1] = fRec285[0];
			fRec276[1] = fRec276[0];
			fRec287[1] = fRec287[0];
			fVec167[1] = fVec167[0];
			fRec274[1] = fRec274[0];
			fRec272[1] = fRec272[0];
			fRec289[1] = fRec289[0];
			fVec169[1] = fVec169[0];
			fRec288[1] = fRec288[0];
			fRec273[1] = fRec273[0];
			fRec290[1] = fRec290[0];
			fVec171[1] = fVec171[0];
			fRec271[1] = fRec271[0];
			fRec269[1] = fRec269[0];
			fRec292[1] = fRec292[0];
			fVec173[1] = fVec173[0];
			fRec291[1] = fRec291[0];
			fRec270[1] = fRec270[0];
			fRec216[1] = fRec216[0];
			fRec293[1] = fRec293[0];
			fRec303[1] = fRec303[0];
			fRec302[1] = fRec302[0];
			fRec305[1] = fRec305[0];
			fRec304[1] = fRec304[0];
			fRec307[1] = fRec307[0];
			fRec306[1] = fRec306[0];
			fRec309[1] = fRec309[0];
			fRec308[1] = fRec308[0];
			fRec311[1] = fRec311[0];
			fRec310[1] = fRec310[0];
			fRec313[1] = fRec313[0];
			fRec312[1] = fRec312[0];
			fRec315[1] = fRec315[0];
			fRec314[1] = fRec314[0];
			fRec317[1] = fRec317[0];
			fRec316[1] = fRec316[0];
			fRec300[1] = fRec300[0];
			fRec298[1] = fRec298[0];
			fRec296[1] = fRec296[0];
			fRec294[1] = fRec294[0];
		}
	}

};

#endif
