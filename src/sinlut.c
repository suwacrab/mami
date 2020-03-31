const unsigned short sinlut[0x0400] =
{
	0x0000,0x0019,0x0032,0x004B,0x0064,0x007D,0x0096,0x00AF,
	0x00C8,0x00E2,0x00FB,0x0114,0x012D,0x0146,0x015F,0x0178,
	0x0191,0x01AA,0x01C3,0x01DC,0x01F5,0x020E,0x0227,0x0240,
	0x0259,0x0271,0x028A,0x02A3,0x02BC,0x02D5,0x02ED,0x0306,
	0x031F,0x0337,0x0350,0x0368,0x0381,0x0399,0x03B2,0x03CA,
	0x03E3,0x03FB,0x0413,0x042C,0x0444,0x045C,0x0474,0x048C,
	0x04A5,0x04BD,0x04D5,0x04EC,0x0504,0x051C,0x0534,0x054C,
	0x0563,0x057B,0x0593,0x05AA,0x05C2,0x05D9,0x05F0,0x0608,
	0x061F,0x0636,0x064D,0x0664,0x067B,0x0692,0x06A9,0x06C0,
	0x06D7,0x06ED,0x0704,0x071B,0x0731,0x0748,0x075E,0x0774,
	0x078A,0x07A0,0x07B7,0x07CD,0x07E2,0x07F8,0x080E,0x0824,
	0x0839,0x084F,0x0864,0x087A,0x088F,0x08A4,0x08B9,0x08CE,
	0x08E3,0x08F8,0x090D,0x0921,0x0936,0x094B,0x095F,0x0973,
	0x0987,0x099C,0x09B0,0x09C4,0x09D7,0x09EB,0x09FF,0x0A12,
	0x0A26,0x0A39,0x0A4D,0x0A60,0x0A73,0x0A86,0x0A99,0x0AAC,
	0x0ABE,0x0AD1,0x0AE3,0x0AF6,0x0B08,0x0B1A,0x0B2C,0x0B3E,
	0x0B50,0x0B62,0x0B73,0x0B85,0x0B96,0x0BA7,0x0BB8,0x0BCA,
	0x0BDA,0x0BEB,0x0BFC,0x0C0D,0x0C1D,0x0C2D,0x0C3E,0x0C4E,
	0x0C5E,0x0C6E,0x0C7D,0x0C8D,0x0C9D,0x0CAC,0x0CBB,0x0CCA,
	0x0CD9,0x0CE8,0x0CF7,0x0D06,0x0D14,0x0D23,0x0D31,0x0D3F,
	0x0D4D,0x0D5B,0x0D69,0x0D77,0x0D84,0x0D91,0x0D9F,0x0DAC,
	0x0DB9,0x0DC6,0x0DD2,0x0DDF,0x0DEB,0x0DF8,0x0E04,0x0E10,
	0x0E1C,0x0E28,0x0E33,0x0E3F,0x0E4A,0x0E55,0x0E60,0x0E6B,
	0x0E76,0x0E81,0x0E8B,0x0E96,0x0EA0,0x0EAA,0x0EB4,0x0EBE,
	0x0EC8,0x0ED1,0x0EDB,0x0EE4,0x0EED,0x0EF6,0x0EFF,0x0F08,
	0x0F10,0x0F18,0x0F21,0x0F29,0x0F31,0x0F39,0x0F40,0x0F48,
	0x0F4F,0x0F56,0x0F5D,0x0F64,0x0F6B,0x0F72,0x0F78,0x0F7F,
	0x0F85,0x0F8B,0x0F91,0x0F96,0x0F9C,0x0FA1,0x0FA7,0x0FAC,
	0x0FB1,0x0FB6,0x0FBA,0x0FBF,0x0FC3,0x0FC7,0x0FCB,0x0FCF,
	0x0FD3,0x0FD7,0x0FDA,0x0FDE,0x0FE1,0x0FE4,0x0FE7,0x0FE9,
	0x0FEC,0x0FEE,0x0FF0,0x0FF2,0x0FF4,0x0FF6,0x0FF8,0x0FF9,
	0x0FFB,0x0FFC,0x0FFD,0x0FFE,0x0FFE,0x0FFF,0x0FFF,0x0FFF,
	0x1000,0x0FFF,0x0FFF,0x0FFF,0x0FFE,0x0FFE,0x0FFD,0x0FFC,
	0x0FFB,0x0FF9,0x0FF8,0x0FF6,0x0FF4,0x0FF2,0x0FF0,0x0FEE,
	0x0FEC,0x0FE9,0x0FE7,0x0FE4,0x0FE1,0x0FDE,0x0FDA,0x0FD7,
	0x0FD3,0x0FCF,0x0FCB,0x0FC7,0x0FC3,0x0FBF,0x0FBA,0x0FB6,
	0x0FB1,0x0FAC,0x0FA7,0x0FA1,0x0F9C,0x0F96,0x0F91,0x0F8B,
	0x0F85,0x0F7F,0x0F78,0x0F72,0x0F6B,0x0F64,0x0F5D,0x0F56,
	0x0F4F,0x0F48,0x0F40,0x0F39,0x0F31,0x0F29,0x0F21,0x0F18,
	0x0F10,0x0F08,0x0EFF,0x0EF6,0x0EED,0x0EE4,0x0EDB,0x0ED1,
	0x0EC8,0x0EBE,0x0EB4,0x0EAA,0x0EA0,0x0E96,0x0E8B,0x0E81,
	0x0E76,0x0E6B,0x0E60,0x0E55,0x0E4A,0x0E3F,0x0E33,0x0E28,
	0x0E1C,0x0E10,0x0E04,0x0DF8,0x0DEB,0x0DDF,0x0DD2,0x0DC6,
	0x0DB9,0x0DAC,0x0D9F,0x0D91,0x0D84,0x0D77,0x0D69,0x0D5B,
	0x0D4D,0x0D3F,0x0D31,0x0D23,0x0D14,0x0D06,0x0CF7,0x0CE8,
	0x0CD9,0x0CCA,0x0CBB,0x0CAC,0x0C9D,0x0C8D,0x0C7D,0x0C6E,
	0x0C5E,0x0C4E,0x0C3E,0x0C2D,0x0C1D,0x0C0D,0x0BFC,0x0BEB,
	0x0BDA,0x0BCA,0x0BB8,0x0BA7,0x0B96,0x0B85,0x0B73,0x0B62,
	0x0B50,0x0B3E,0x0B2C,0x0B1A,0x0B08,0x0AF6,0x0AE3,0x0AD1,
	0x0ABE,0x0AAC,0x0A99,0x0A86,0x0A73,0x0A60,0x0A4D,0x0A39,
	0x0A26,0x0A12,0x09FF,0x09EB,0x09D7,0x09C4,0x09B0,0x099C,
	0x0987,0x0973,0x095F,0x094B,0x0936,0x0921,0x090D,0x08F8,
	0x08E3,0x08CE,0x08B9,0x08A4,0x088F,0x087A,0x0864,0x084F,
	0x0839,0x0824,0x080E,0x07F8,0x07E2,0x07CD,0x07B7,0x07A0,
	0x078A,0x0774,0x075E,0x0748,0x0731,0x071B,0x0704,0x06ED,
	0x06D7,0x06C0,0x06A9,0x0692,0x067B,0x0664,0x064D,0x0636,
	0x061F,0x0608,0x05F0,0x05D9,0x05C2,0x05AA,0x0593,0x057B,
	0x0563,0x054C,0x0534,0x051C,0x0504,0x04EC,0x04D5,0x04BD,
	0x04A5,0x048C,0x0474,0x045C,0x0444,0x042C,0x0413,0x03FB,
	0x03E3,0x03CA,0x03B2,0x0399,0x0381,0x0368,0x0350,0x0337,
	0x031F,0x0306,0x02ED,0x02D5,0x02BC,0x02A3,0x028A,0x0271,
	0x0259,0x0240,0x0227,0x020E,0x01F5,0x01DC,0x01C3,0x01AA,
	0x0191,0x0178,0x015F,0x0146,0x012D,0x0114,0x00FB,0x00E2,
	0x00C8,0x00AF,0x0096,0x007D,0x0064,0x004B,0x0032,0x0019,
	0x0000,0xFFE6,0xFFCD,0xFFB4,0xFF9B,0xFF82,0xFF69,0xFF50,
	0xFF37,0xFF1D,0xFF04,0xFEEB,0xFED2,0xFEB9,0xFEA0,0xFE87,
	0xFE6E,0xFE55,0xFE3C,0xFE23,0xFE0A,0xFDF1,0xFDD8,0xFDBF,
	0xFDA6,0xFD8E,0xFD75,0xFD5C,0xFD43,0xFD2A,0xFD12,0xFCF9,
	0xFCE0,0xFCC8,0xFCAF,0xFC97,0xFC7E,0xFC66,0xFC4D,0xFC35,
	0xFC1C,0xFC04,0xFBEC,0xFBD3,0xFBBB,0xFBA3,0xFB8B,0xFB73,
	0xFB5A,0xFB42,0xFB2A,0xFB13,0xFAFB,0xFAE3,0xFACB,0xFAB3,
	0xFA9C,0xFA84,0xFA6C,0xFA55,0xFA3D,0xFA26,0xFA0F,0xF9F7,
	0xF9E0,0xF9C9,0xF9B2,0xF99B,0xF984,0xF96D,0xF956,0xF93F,
	0xF928,0xF912,0xF8FB,0xF8E4,0xF8CE,0xF8B7,0xF8A1,0xF88B,
	0xF875,0xF85F,0xF848,0xF832,0xF81D,0xF807,0xF7F1,0xF7DB,
	0xF7C6,0xF7B0,0xF79B,0xF785,0xF770,0xF75B,0xF746,0xF731,
	0xF71C,0xF707,0xF6F2,0xF6DE,0xF6C9,0xF6B4,0xF6A0,0xF68C,
	0xF678,0xF663,0xF64F,0xF63B,0xF628,0xF614,0xF600,0xF5ED,
	0xF5D9,0xF5C6,0xF5B2,0xF59F,0xF58C,0xF579,0xF566,0xF553,
	0xF541,0xF52E,0xF51C,0xF509,0xF4F7,0xF4E5,0xF4D3,0xF4C1,
	0xF4AF,0xF49D,0xF48C,0xF47A,0xF469,0xF458,0xF447,0xF435,
	0xF425,0xF414,0xF403,0xF3F2,0xF3E2,0xF3D2,0xF3C1,0xF3B1,
	0xF3A1,0xF391,0xF382,0xF372,0xF362,0xF353,0xF344,0xF335,
	0xF326,0xF317,0xF308,0xF2F9,0xF2EB,0xF2DC,0xF2CE,0xF2C0,
	0xF2B2,0xF2A4,0xF296,0xF288,0xF27B,0xF26E,0xF260,0xF253,
	0xF246,0xF239,0xF22D,0xF220,0xF214,0xF207,0xF1FB,0xF1EF,
	0xF1E3,0xF1D7,0xF1CC,0xF1C0,0xF1B5,0xF1AA,0xF19F,0xF194,
	0xF189,0xF17E,0xF174,0xF169,0xF15F,0xF155,0xF14B,0xF141,
	0xF137,0xF12E,0xF124,0xF11B,0xF112,0xF109,0xF100,0xF0F7,
	0xF0EF,0xF0E7,0xF0DE,0xF0D6,0xF0CE,0xF0C6,0xF0BF,0xF0B7,
	0xF0B0,0xF0A9,0xF0A2,0xF09B,0xF094,0xF08D,0xF087,0xF080,
	0xF07A,0xF074,0xF06E,0xF069,0xF063,0xF05E,0xF058,0xF053,
	0xF04E,0xF049,0xF045,0xF040,0xF03C,0xF038,0xF034,0xF030,
	0xF02C,0xF028,0xF025,0xF021,0xF01E,0xF01B,0xF018,0xF016,
	0xF013,0xF011,0xF00F,0xF00D,0xF00B,0xF009,0xF007,0xF006,
	0xF004,0xF003,0xF002,0xF001,0xF001,0xF000,0xF000,0xF000,
	0xF000,0xF000,0xF000,0xF000,0xF001,0xF001,0xF002,0xF003,
	0xF004,0xF006,0xF007,0xF009,0xF00B,0xF00D,0xF00F,0xF011,
	0xF013,0xF016,0xF018,0xF01B,0xF01E,0xF021,0xF025,0xF028,
	0xF02C,0xF030,0xF034,0xF038,0xF03C,0xF040,0xF045,0xF049,
	0xF04E,0xF053,0xF058,0xF05E,0xF063,0xF069,0xF06E,0xF074,
	0xF07A,0xF080,0xF087,0xF08D,0xF094,0xF09B,0xF0A2,0xF0A9,
	0xF0B0,0xF0B7,0xF0BF,0xF0C6,0xF0CE,0xF0D6,0xF0DE,0xF0E7,
	0xF0EF,0xF0F7,0xF100,0xF109,0xF112,0xF11B,0xF124,0xF12E,
	0xF137,0xF141,0xF14B,0xF155,0xF15F,0xF169,0xF174,0xF17E,
	0xF189,0xF194,0xF19F,0xF1AA,0xF1B5,0xF1C0,0xF1CC,0xF1D7,
	0xF1E3,0xF1EF,0xF1FB,0xF207,0xF214,0xF220,0xF22D,0xF239,
	0xF246,0xF253,0xF260,0xF26E,0xF27B,0xF288,0xF296,0xF2A4,
	0xF2B2,0xF2C0,0xF2CE,0xF2DC,0xF2EB,0xF2F9,0xF308,0xF317,
	0xF326,0xF335,0xF344,0xF353,0xF362,0xF372,0xF382,0xF391,
	0xF3A1,0xF3B1,0xF3C1,0xF3D2,0xF3E2,0xF3F2,0xF403,0xF414,
	0xF425,0xF435,0xF447,0xF458,0xF469,0xF47A,0xF48C,0xF49D,
	0xF4AF,0xF4C1,0xF4D3,0xF4E5,0xF4F7,0xF509,0xF51C,0xF52E,
	0xF541,0xF553,0xF566,0xF579,0xF58C,0xF59F,0xF5B2,0xF5C6,
	0xF5D9,0xF5ED,0xF600,0xF614,0xF628,0xF63B,0xF64F,0xF663,
	0xF678,0xF68C,0xF6A0,0xF6B4,0xF6C9,0xF6DE,0xF6F2,0xF707,
	0xF71C,0xF731,0xF746,0xF75B,0xF770,0xF785,0xF79B,0xF7B0,
	0xF7C6,0xF7DB,0xF7F1,0xF807,0xF81D,0xF832,0xF848,0xF85F,
	0xF875,0xF88B,0xF8A1,0xF8B7,0xF8CE,0xF8E4,0xF8FB,0xF912,
	0xF928,0xF93F,0xF956,0xF96D,0xF984,0xF99B,0xF9B2,0xF9C9,
	0xF9E0,0xF9F7,0xFA0F,0xFA26,0xFA3D,0xFA55,0xFA6C,0xFA84,
	0xFA9C,0xFAB3,0xFACB,0xFAE3,0xFAFB,0xFB13,0xFB2A,0xFB42,
	0xFB5A,0xFB73,0xFB8B,0xFBA3,0xFBBB,0xFBD3,0xFBEC,0xFC04,
	0xFC1C,0xFC35,0xFC4D,0xFC66,0xFC7E,0xFC97,0xFCAF,0xFCC8,
	0xFCE0,0xFCF9,0xFD12,0xFD2A,0xFD43,0xFD5C,0xFD75,0xFD8E,
	0xFDA6,0xFDBF,0xFDD8,0xFDF1,0xFE0A,0xFE23,0xFE3C,0xFE55,
	0xFE6E,0xFE87,0xFEA0,0xFEB9,0xFED2,0xFEEB,0xFF04,0xFF1D,
	0xFF37,0xFF50,0xFF69,0xFF82,0xFF9B,0xFFB4,0xFFCD,0xFFE6,
	
};
