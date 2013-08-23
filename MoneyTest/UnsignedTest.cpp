#include "gtest/gtest.h"

// reivew common coding in PIM, testing for change to FIELDID/u8
// test comparison; fid < 0 ; fid >= MAXFIELDS
// test assignment of -1 as invalid fieldid

typedef unsigned char      u8, * LPU8;
typedef u8          FIELDID,  * LPFIELDID;

#define INVALIDFIELDID     (u8)(0xFF) /* MAXFIELDS - change to u8, so need to handle -1/invalid fieldid */
#define MAXFIELDS          252          /* maximum number of fields DESIGNED FOR FUTURE USE*/
#define FIRSTVALID          2          /* start of valid fields */

// MACROs to consolidate checking/casting new FIELDID (u8) data type 
#define IsInvalidFIELDID(a) ( INVALIDFIELDID == (a) )


// return int -1, similar to PIM code that is not updated for u8/FIELDID
int returnNegativeOneInt()
{
   return -1;
}

TEST(testUnsignedType, testNegativeOneAssignment) {
   FIELDID fid;

   // assign i32 -1 value; does it truncate? convert to -1?
   fid = (FIELDID)returnNegativeOneInt(); 
   
   // with i8/FIELDID this was true: EXPECT_EQ(-1, fid);
   EXPECT_NE(-1, fid);
   EXPECT_EQ(INVALIDFIELDID, fid);
} // end of testNegativeOneAssignment


TEST(testUnsignedType, testNegativeOneComparison) {
   // assign i32 -1 value; does it truncate? convert to -1?
   FIELDID fid = (FIELDID)returnNegativeOneInt(); 

   // with i8/FIELDID this was true: EXPECT_TRUE(fid < 0);
   EXPECT_FALSE(fid < 0);
   EXPECT_TRUE(fid >= MAXFIELDS);      
   
//C:\dev\esrm50\pim\detail\DETAIL.CPP(411):   if (c < FIRSTVALID || c >= MAXFIELDS)
//C:\dev\esrm50\pim\detail\DETAIL.CPP(484):   if ( FieldID < 0 || FieldID >= MAXFIELDS )
//C:\dev\esrm50\pim\detail\DETAIL.CPP(562):   if ( FieldID < 0 || FieldID >= MAXFIELDS )
   /*FieldID = (FIELDID)GetSelectedData(hDlg, IDLISTB);
   if (FieldID < 0 || FieldID >= MAXFIELDS)
      return 0;*/
   EXPECT_TRUE(fid < 0 || fid >= MAXFIELDS);
   // with i8/FIELDID this was true: EXPECT_TRUE(fid < 0 );
   EXPECT_FALSE(fid < 0 );
   EXPECT_TRUE(fid >= MAXFIELDS);
   EXPECT_TRUE(IsInvalidFIELDID(fid) || fid >= MAXFIELDS);

   // if (lpFF[i].FieldID < FIRSTVALID || lpFF[i].FieldID >= MAXFIELDS)
   EXPECT_TRUE(fid < FIRSTVALID || fid >= MAXFIELDS );
   // with i8/FIELDID this was true: EXPECT_TRUE(fid < FIRSTVALID )
   EXPECT_FALSE(fid < FIRSTVALID );
   EXPECT_TRUE(fid >= MAXFIELDS );

   //if (FieldID < FIRSTVALID || MAXFIELDS <= FieldID || lpAOB == NULL)
   EXPECT_TRUE(fid < FIRSTVALID || MAXFIELDS <= fid );
   // with i8/FIELDID this was true: EXPECT_TRUE(fid < FIRSTVALID );
   EXPECT_FALSE(fid < FIRSTVALID );
   EXPECT_TRUE(MAXFIELDS <= fid );


   //if (FieldID == INVALIDFIELDID || FieldID < FIRSTVALID || MAXFIELDS <= FieldID || lpAOB == NULL)
   EXPECT_TRUE(fid == INVALIDFIELDID || fid < FIRSTVALID || MAXFIELDS <= fid );
   EXPECT_TRUE(fid == INVALIDFIELDID );
   // with i8/FIELDID this was true: EXPECT_TRUE( fid < FIRSTVALID );
   EXPECT_FALSE( fid < FIRSTVALID );
   EXPECT_TRUE(MAXFIELDS <= fid );

   /*if (nCount < 0 || nCount > MAXFIELDS)
      return MAKE_HRESULT(SEVERITY_ERROR, 0, ERROR_INVALID_PARAMETER);*/
   EXPECT_TRUE(fid < 0 || fid> MAXFIELDS);
   // with i8/FIELDID this was true: EXPECT_TRUE(fid < 0 );
   EXPECT_FALSE(fid < 0 );
   EXPECT_TRUE( fid> MAXFIELDS);

   //if (FieldID == INVALIDFIELDID || FieldID >= MAXFIELDS)
   EXPECT_TRUE(fid == INVALIDFIELDID || fid >= MAXFIELDS);
   EXPECT_TRUE(fid == INVALIDFIELDID );
   EXPECT_TRUE(fid >= MAXFIELDS);

   //if ( lpOrder[idx] < FIRSTVALID )
   // with i8/FIELDID this was true: EXPECT_TRUE( fid < FIRSTVALID );
   EXPECT_FALSE( fid < FIRSTVALID );

   /*C:\dev\esrm50\pim\detail\formrunview.cpp(5196):		
   if ( ( (EveryField = HasAnEveryField(hWnd, lpa->Fields)) > FIRSTVALID) && EveryField <= MAXFIELDS )*/
   EXPECT_FALSE ( (fid > FIRSTVALID) && fid <= MAXFIELDS );
   // with i8/FIELDID this was true: EXPECT_FALSE ( (fid > FIRSTVALID) );
   EXPECT_TRUE( (fid > FIRSTVALID) );
   EXPECT_FALSE (  fid <= MAXFIELDS );
} // end of testNegativeOneComparison

TEST(testUnsignedType, testINVALIDFIELDIDComparision) {
   FIELDID fid = INVALIDFIELDID;

   EXPECT_FALSE(fid < 0);
   EXPECT_TRUE(fid >= MAXFIELDS);      

   // this fails due to compare with MAXFIELDS (u8)(0xff) = 255 > MAXFIELDS = 252
   //EXPECT_FALSE(fid < 0 || fid >= MAXFIELDS );
   //EXPECT_FALSE(FieldID < 0 || FieldID >= MAXFIELDS)

   // Replace with IsInvalidFIELDID macro
   EXPECT_TRUE(IsInvalidFIELDID(fid) || fid >= MAXFIELDS ); 
   EXPECT_TRUE(IsInvalidFIELDID(fid));
   EXPECT_TRUE(fid >= MAXFIELDS ); 
} // end of testINVALIDFIELDIDComparision