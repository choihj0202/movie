
void* mv_genMvInfo(char* name, float score, int runTime, char* country);	// ���� ������ �����ϴ� �Լ�
void printMv(void* obj);	// ��ȭ ������ ����ϴ� �Լ�
int mv_printAll(void* obj, void* arg);	// ��� ��ȭ�� ����ϴ� �Լ�
int mv_printCountry(void* obj, void* arg);	// Ư�� ���� ������ ��ȭ�� ����ϴ� �Լ�
int mv_printScore(void* obj, void* arg);	// Ư�� ������ ��ȭ�� ����ϴ� �Լ�
int mv_printRunTime(void* obj, void* arg);	// Ư�� runtime�� ��ȭ�� ����ϴ� �Լ�
