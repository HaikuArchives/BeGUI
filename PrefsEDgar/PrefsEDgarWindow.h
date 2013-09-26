//BPPPrefsEDgarWindow.h

#ifndef PREFWINDOW
#define PREFWINDOW
	#define ABOUT_PREFWINDOW 'aBAp'

	class
	PrefsEDgarWindow	:
	public ScrollingWindow
	{
	private:
							PrefsEDgarWindow(		const PrefsEDgarWindow& copy);//not implemented on purpose
		PrefsEDgarWindow&	operator = (	const PrefsEDgarWindow& assign);//not implemented on purpose
	public:
							PrefsEDgarWindow(	void);
							~PrefsEDgarWindow();
		virtual bool		QuitRequested(		void);
		virtual void		MessageReceived(	BMessage *	pparamMessage);
	};
#endif