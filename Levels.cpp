#include "stdafx.h"

extern const int LevelCount = 3;

extern int Levels[][30][10] =
{
	// LEVEL 1
	{
		{0        ,0        ,00       ,00       ,00       ,00       ,00       ,00       ,0        ,0       },
		{0        ,0        ,000      ,100      ,100      ,100      ,100      ,000      ,0        ,0       },
		{00       ,000      ,100      ,150      ,150      ,150      ,150      ,100      ,000      ,00      },
		{0        ,100      ,150      ,200      ,200      ,200      ,200      ,150      ,100      ,0       },
		{0        ,100      ,150      ,200      ,500      ,500      ,200      ,150      ,100      ,0       },
		{0        ,100      ,150      ,200      ,1000     ,1000     ,200      ,150      ,100      ,0       },
		{0        ,100      ,150      ,200      ,500      ,500      ,200      ,150      ,100      ,0       },
		{0        ,100      ,150      ,200      ,200      ,200      ,200      ,150      ,100      ,0       },
		{0        ,100      ,150      ,150      ,150      ,150      ,150      ,150      ,100      ,0       },
		{0        ,0        ,100      ,100      ,100      ,100      ,100      ,100      ,0        ,0       },

		{0        ,0        ,0        ,100      ,100      ,100      ,100      ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },

		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0}
	},

	// LEVEL 2

	{
		{1000     ,0        ,1000     ,0        ,1000     ,5000     ,5000     ,1000     ,0        ,1000    },
		{500      ,0        ,500      ,0        ,500      ,0        ,0        ,500      ,0        ,500     },
		{500      ,0        ,500      ,0        ,500      ,0        ,0        ,500      ,0        ,500     },
		{200      ,0        ,200      ,0        ,200      ,0        ,0        ,200      ,0        ,200     },
		{200      ,0        ,200      ,0        ,200      ,0        ,0        ,200      ,0        ,200     },
		{200      ,0        ,200      ,0        ,200      ,0        ,0        ,200      ,0        ,200     },
		{200      ,0        ,200      ,0        ,200      ,0        ,0        ,200      ,0        ,200     },
		{100      ,0        ,100      ,0        ,100      ,0        ,0        ,100      ,0        ,100     },
		{100      ,0        ,100      ,0        ,100      ,0        ,0        ,100      ,0        ,100     },
		{100      ,0        ,100      ,0        ,100      ,0        ,0        ,100      ,0        ,100     },

		{100      ,0        ,100      ,0        ,100      ,0        ,0        ,100      ,0        ,100     },
		{100      ,0        ,100      ,0        ,100      ,0        ,0        ,100      ,0        ,100     },
		{100      ,0        ,100      ,0        ,100      ,0        ,0        ,100      ,0        ,100     },
		{100      ,0        ,100      ,0        ,100      ,0        ,0        ,100      ,0        ,100     },
		{100      ,0        ,100      ,0        ,100      ,0        ,0        ,100      ,0        ,100     },
		{-1       ,0        ,-1       ,0        ,-1       ,-1       ,-1       ,-1       ,0        ,-1      },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },

		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0}
	},

	// LEVEL 3

	{
		{4560     ,0        ,1        ,0        ,0        ,0        ,0        ,456      ,0        ,0       },
		{-1       ,0        ,-1       ,100      ,105      ,0        ,0        ,456      ,0        ,0       },
		{0        ,0        ,2        ,0        ,200      ,0        ,0        ,456      ,0        ,0       },
		{0        ,0        ,3        ,0        ,0        ,300      ,0        ,100      ,0        ,0       },
		{0        ,0        ,8        ,15165    ,45456    ,150      ,0        ,1        ,0        ,0       },
		{0        ,0        ,546      ,445      ,456      ,163      ,0        ,0        ,0        ,0       },
		{0        ,0        ,465      ,0        ,0        ,456      ,0        ,1        ,0        ,0       },
		{0        ,0        ,444      ,0        ,0        ,123      ,0        ,1        ,0        ,0       },
		{0        ,0        ,646      ,0        ,0        ,156      ,0        ,223        ,0        ,0       },
		{0        ,0        ,55       ,0        ,0        ,345      ,0        ,545        ,0        ,0       },

		{0        ,100      ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },

		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{-1       ,0        ,0        ,0        ,-1       ,0        ,0        ,0        ,0        ,-1      },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0       },
		{0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0        ,0}
	},


};
