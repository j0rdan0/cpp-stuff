#include <stdio>
#include <windows.h>

void fperror(DWORD);

using namespace std;

int main() {
	cout << "debug";
	return 0;
}
void fperror(DWORD errCode) {
	LPVOID msg = NULL;
	DWORD systemLocale = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);

	if (FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, errCode, systemLocale, (PTSTR)&msg, 0, NULL)) {
		if (!msg) {
			printf("[-] error string not available\n");
		}
		else {
			wprintf(L"[-] %ls", (LPWSTR)msg);
		}
	}
}
