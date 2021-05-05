// ---------------------------------------------------------------------------

#pragma hdrstop

#include "TSCPrinter.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

TTSCPrinterHelper::TTSCPrinterHelper(str DllName)
{
	Initialize(DllName);
}

// ---------------------------------------------------------------------------
TTSCPrinterHelper::TTSCPrinterHelper(str DllName, str PortName)
{
	Initialize(DllName);
	OpenPort(PortName);
}

// ---------------------------------------------------------------------------
TTSCPrinterHelper::~TTSCPrinterHelper()
{
	ClosePort();
	FreeLibrary(hInst);
}

// ---------------------------------------------------------------------------
bool TTSCPrinterHelper::Initialize(str DllName)
{
	hInst = LoadLibraryA(DllName.c_str());
	Active = hInst;

	if (hInst)
	{
		(FARPROC&)about = GetProcAddress(hInst, "about");
		(FARPROC&)openport = GetProcAddress(hInst, "openport");
		(FARPROC&)closeport = GetProcAddress(hInst, "closeport");
		(FARPROC&)sendcommand = GetProcAddress(hInst, "sendcommand");
		(FARPROC&)setup = GetProcAddress(hInst, "setup");
		(FARPROC&)clearbuffer = GetProcAddress(hInst, "clearbuffer");
		(FARPROC&)barcode = GetProcAddress(hInst, "barcode");
		(FARPROC&)printerfont = GetProcAddress(hInst, "printerfont");
		(FARPROC&)windowsfont = GetProcAddress(hInst, "windowsfont");

		return true;
	}

	return false;
}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::About()
{
	if (!Active)
		return 0;

	return about();
}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::OpenPort(str PrinterName)
{
	if (!Active)
		return 0;

	PortOpened = openport(PrinterName);
	return PortOpened;

}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::ClosePort()
{
	if (!Active)
		return 0;

	if (PortOpened)
		PortOpened = !closeport();

	return PortOpened;
}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::Sendcommand(str Command)
{
	if (!Active)
		return 0;

	return sendcommand(Command);
}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::Setup(str a, str b, str c, str d, str e, str f, str g)
{
	if (!Active)
		return 0;

	return setup(a, b, c, d, e, f, g);
}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::ClearBuffer()
{
	if (!Active)
		return 0;

	return clearbuffer();
}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::Barcode(str a, str b, str c, str d, str e, str f, str g, str h, str i)
{
	if (!Active)
		return 0;

	return barcode(a, b, c, d, e, f, g, h, i);
}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::PrinterFont(str a, str b, str c, str d, str e, str f, str g)
{
	if (!Active)
		return 0;

	return printerfont(a, b, c, d, e, f, g);
}

// ---------------------------------------------------------------------------
int TTSCPrinterHelper::WindowsFont(str a, str b, str c, str d, str e, str f, str g, str h, str i)
{
	if (!Active)
		return 0;

	return windowsfont(a, b, c, d, e, f, g, h, i);
}
// ---------------------------------------------------------------------------
