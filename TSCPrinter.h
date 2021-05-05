// ---------------------------------------------------------------------------

#ifndef TSCPrinterH
#define TSCPrinterH

#include <Classes.hpp>

class TTSCPrinterHelper
{
	typedef AnsiString str;

	HINSTANCE hInst;

	bool Initialize(str DllName);

	// dll Function Define
	int CALLBACK(*about)(void);
	int CALLBACK(*openport)(str PrinterName);
	int CALLBACK(*closeport)(void);
	int CALLBACK(*sendcommand)(str Command);
	int CALLBACK(*setup)(str a, str b, str c, str d, str e, str f, str g);
	int CALLBACK(*clearbuffer)(void);
	int CALLBACK(*barcode)(str a, str b, str c, str d, str e, str f, str g, str h, str i);
	int CALLBACK(*printerfont)(str a, str b, str c, str d, str e, str f, str g);
	int CALLBACK(*windowsfont)(str a, str b, str c, str d, str e, str f, str g, str h, str i);

public:
	bool Active;
	bool PortOpened;

	TTSCPrinterHelper(str DllName);
	TTSCPrinterHelper(str DllName, str PortName);
	~TTSCPrinterHelper();

	int About();
	int OpenPort(str PrinterName);
	int ClosePort();
	int Sendcommand(str Command);
	int Setup(str a, str b, str c, str d, str e, str f, str g);
	int ClearBuffer();
	int Barcode(str a, str b, str c, str d, str e, str f, str g, str h, str i);
	int PrinterFont(str a, str b, str c, str d, str e, str f, str g);
	int WindowsFont(str a, str b, str c, str d, str e, str f, str g, str h, str i);
};
// ---------------------------------------------------------------------------
#endif
