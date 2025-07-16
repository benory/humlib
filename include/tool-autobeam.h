//
// Programmer:    Craig Stuart Sapp <craig@ccrma.stanford.edu>
// Creation Date: Wed Nov 30 20:36:38 PST 2016
// Last Modified: Wed Nov 30 20:36:41 PST 2016
// Filename:      tool-autobeam.h
// URL:           https://github.com/craigsapp/humlib/blob/master/include/tool-autobeam.h
// Syntax:        C++11; humlib
// vim:           syntax=cpp ts=3 noexpandtab nowrap
//
// Description:   Interface for autobeam tool.
//

#ifndef _TOOL_AUTOBEAM_H_INCLUDED
#define _TOOL_AUTOBEAM_H_INCLUDED

#include "HumTool.h"
#include "HumdrumFileSet.h"

namespace hum {

// START_MERGE


class Tool_autobeam : public HumTool {
	public:
		             Tool_autobeam       (void);
		            ~Tool_autobeam       () {};

		bool         run                 (HumdrumFile& infile);
		bool         run                 (HumdrumFileSet& infiles);
		bool         run                 (const std::string& indata, std::ostream& out);
		bool         run                 (HumdrumFile& infile, std::ostream& out);

	protected:
		void         initialize          (HumdrumFile& infile);
		void         processStrand       (HTp strandstart, HTp strandend);
		void         processMeasure      (std::vector<HTp>& measure);
		void         addBeam             (HTp startnote, HTp endnote);
		void         addBeams            (HumdrumFile& infile);
		void         beamGraceNotes      (HumdrumFile& infile);
		std::string  getBeamFromDur      (HTp token, const std::string& text);
		void         removeQqMarks       (HTp stok, HTp etok);
		void         removeQqMarks       (HTp tok);
		void         removeBeams         (HumdrumFile& infile);
		void         removeEdgeRests     (HTp& startnote, HTp& endnote);
		void         breakBeamsByLyrics  (HumdrumFile& infile);
		void         processStrandForLyrics(HTp stok, HTp etok);
		bool         hasSyllable         (HTp token);
		void         splitBeam           (HTp tok, HTp stok, HTp etok);
		void         splitBeam2          (std::vector<HTp>& group, HTp tok);
		void         getBeamedNotes      (std::vector<HTp>& toks, HTp tok, HTp stok, HTp etok);
		bool         isLazy              (std::vector<HTp>& group);
		void         splitBeamLazy       (std::vector<HTp>& group, HTp tok);
		void         splitBeamNotLazy    (std::vector<HTp>& group, HTp tok);
		void         removeBeamCharacters(HTp token);

	private:
		std::vector<std::vector<std::pair<int, HumNum> > > m_timesigs;
		std::vector<HTp> m_kernspines;
		bool        m_overwriteQ = false;
		std::vector<bool> m_tracks;
		bool        m_includerests = false;
		int         m_splitcount = 0;
		HumNum      m_duration = 0;

};

// END_MERGE

} // end namespace hum

#endif /* _TOOL_AUTOBEAM_H_INCLUDED */



