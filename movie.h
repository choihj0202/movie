
void* mv_genMvInfo(char* name, float score, int runTime, char* country);	// 영봐 정보를 생성하는 함수
void printMv(void* obj);	// 영화 정보를 출력하는 함수
int mv_printAll(void* obj, void* arg);	// 모든 영화를 출력하는 함수
int mv_printCountry(void* obj, void* arg);	// 특정 제작 국가의 영화를 출력하는 함수
int mv_printScore(void* obj, void* arg);	// 특정 평점의 영화를 출력하는 함수
int mv_printRunTime(void* obj, void* arg);	// 특정 runtime의 영화를 출력하는 함수
