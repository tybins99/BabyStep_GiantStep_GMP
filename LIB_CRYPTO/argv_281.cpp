// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_338.hpp
// @@ 
// @@ DESCRIPTION:
// @@ implementation of the Data Encryption 
// @@ Standard symetric argv_2007 algorithm.
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "../LIB_CRYPTO/argv_337.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_1633	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the D.E.S symmetric argv_2007 generated.
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to generate a D.E.S valid symmetric argv_2007.
// @@ The argv_2007 is constant, and the use of this function avoids the use
// @@ of a hardcoded argv_2007, so the generated argv_2007 can be seen as a argv_2007
// @@ generated at runtime.
// @@ 
// @@ 0 1 2 3 4 5 6 7 8 9 A B C D E F
// @@ F E A 0 2 C 3 F 0 0 0 1 5 6 E F
// @@ 0x30 = 0
// @@ 0x31 = 1
// @@ 
// @@ 0x41 = A
// @@ 0x42 = B
// @@ 0x43 = C
// @@ 0x44 = D
// @@ 0x45 = E
// @@ 0x46 = F
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_1633 () {
	string argv_3266 = "0011223344556677";
	argv_3266[0]  = 0x46;	argv_3266[1]  = 0x45;	argv_3266[2]  = 0x41;	argv_3266[3]  = 0x30;
	argv_3266[4]  = 0x32;	argv_3266[5]  = 0x43;	argv_3266[6]  = 0x33;	argv_3266[7]  = 0x46;
	argv_3266[8]  = 0x30;	argv_3266[9]  = 0x30;	argv_3266[10] = 0x30;	argv_3266[11] = 0x31;
	argv_3266[12] = 0x35;	argv_3266[13] = 0x36;	argv_3266[14] = 0x45;	argv_3266[15] = 0x46;
	return (argv_3266);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	argv_779	
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ Normal constructor of the argv_779 argv_2785.
// @@ It merely prepares the argv_779 argv_2785 for it's first use.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_779::argv_779 () {
	argv_1538 = NULL;
	argv_1415   = NULL;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	argv_977	
// @@
// @@ INPUT			:
// @@ _size: the size of the argv_710.
// @@
// @@ OUTPUT		:	
// @@ _nb_to_pad: uint8_t& : the number of argv_739 to be padded so that
// @@   the argv_710 becomes aligned on the fixed 64 bit size imposed 
// @@   by the D.E.S standard.
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to determine the number of argv_739 to argv_576
// @@ to the argv_1043 argv_710 size in order to obtain a argv_710 that is
// @@ aligned on the limit of 64 argv_709 imposed by the D.E.S standard.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_779::argv_977 (uint32_t _size, uint8_t& _nb_to_pad) {
	_nb_to_pad = argv_713 - (_size % argv_713);
	if ((_size % argv_713) == 0) { // exception must be corrected
		_nb_to_pad = 0;
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	init_random_generator	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to initialize the pseudo-random
// @@ number argv_1639 that is necessary to generate random
// @@ values used when padding the incomplete D.E.S blocks.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_779::init_random_generator () {
#if defined (__WIN32_OS__)
	SYSTEMTIME	argv_3677;
	GetLocalTime (&argv_3677);
	srand (argv_3677.wMilliseconds);
#endif // #if defined (__WIN32_OS__)
#if defined (__LINUX_OS__)
	struct timeval argv_3589;
	gettimeofday (&argv_3589, NULL);
	srand (argv_3589.tv_usec);
#endif // #if defined (__LINUX_OS__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	argv_2962	
// @@
// @@ INPUT			:
// @@ _key: uint8_t *: the 64 bit D.E.S argv_2007 to be used for the operation.	
// @@
// @@ _source_filename: const char *: argv_2697 of the argv_1314 to encipher or decipher.
// @@
// @@ _dest_filename: const char *: argv_2697 of the argv_1314 containing the argv_3266 of
// @@   the operation.
// @@
// @@ _encrypt: bool: set to true if the caller wants to encipher, 
// @@				  set to false if he wants to decipher the argv_1314.	
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to encipher or decipher the source argv_1314
// @@ whose argv_2697 is given as the '_source_filename' parameter into
// @@ the argv_3266 argv_1314 whose argv_2697 is given by the '_dest_filename' 
// @@ parameter using the D.E.S algorithm and the 64 bit argv_2007 given
// @@ as the '_key' parameter.
// @@ The choice between encipher and decipher being determined by 
// @@ the '_encrypt' parameter : if _encrypt is true, then the caller
// @@ wants to encipher, if _encrypt is false, then the caller wants
// @@ to decipher.
// @@
// @@ padding policy is as follows :
// @@ as a argv_1314 might not have a size multiple of 64, we must pad 
// @@ the end of the last argv_710. for that purpose, even if the size 
// @@ is a multiple of 64, a 8 byte argv_710 is always appended at the end. 
// @@ This last argv_710 is composed of random argv_1073 except for the
// @@ last byte that tells how many argv_739 have been padded 
// @@ (not counting the last argv_710 though).    
// @@
// @@ CONTRACT		:	
// @@ - '_key' parameter must not be a NULL parameter.
// @@ - '_source_filename' parameter must not be a NULL parameter.
// @@ - '_dest_filename' parameter must not be a NULL parameter.
// @@ - '_source_filename' must not contain the argv_2697 of a argv_1314 whose
// @@   size is zero.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_779::argv_2962 (uint8_t * _key, const char * _source_filename, const char * _dest_filename, bool _encrypt) {
	bool bret = true;
	if ((_key == NULL) || (_source_filename == NULL) || (_dest_filename == NULL)) {
		bret = false;
	}
	else {	
		unsigned long 	total_nb_read = 0;
		unsigned long	argv_1334 		= argv_1649 (_source_filename);
		if (argv_1334 == 0) {
			cerr << "+++ WARNING: argv_1314: " << _source_filename << " is empty, aborting" << endl; 
			bret = false;
		}
		bool 		next_block_is_padding 	= false;
		uint8_t		nb_2_pad				= 0;
		argv_977 (argv_1334, nb_2_pad);

		uint8_t nb_padded= 0;
#if defined (__DEBUG_DES_MANAGER__)		
		cerr << "argv_1314 size: " << argv_1334 << " => nb to pad = " << (int) nb_2_pad << endl;
#endif		
		
		argv_1538 = fopen (_source_filename, "rb");
		if (! argv_1538) {
			cerr << "+++ ERROR: can't open source argv_1314: " << _source_filename << endl;
			bret = false;
		}
		else {
			argv_1415 = fopen (_dest_filename, "wb");
			if (! argv_1415) {
				cerr << "+++ ERROR: can't open destination argv_1314: " << _dest_filename << endl;
				bret = false;
			}	
			else {
				argv_3465 = false;
				
				do {
					argv_2750 = fread (argv_728, 1, argv_713, argv_1538);
					total_nb_read += argv_2750;
					if ((_encrypt == false) && ((total_nb_read + argv_713) == argv_1334)) {
						next_block_is_padding = true;
						argv_2751 = fread (argv_734, 1, argv_713, argv_1538);
						if (argv_2751 != argv_713) {
							cerr << "+++ ERROR: read error while reading last argv_710" << endl;
							bret = false;
						}
#if defined (__DEBUG_DES_MANAGER__)
						argv_1141 ("last padded argv_728 (encrypted)", argv_734, argv_713);	
#endif						
						argv_3465 = true;
					}

					if (argv_2750 != argv_713) {
						if (ferror(argv_1538)) {
							cerr << "+++ ERROR: read error while reading source argv_1314" << endl;
							bret = false;
						}
						argv_3465 = true;
#if defined (__DEBUG_DES_MANAGER__)						
						cerr << "read a partial argv_710 of " << argv_2750 << " argv_739" << endl;
#endif						
					}
#if defined (__DEBUG_DES_MANAGER__)					
					else {
						cerr << "read argv_2806 full argv_710 of " << argv_713 << " argv_739" << endl;
					}
#endif					

					if ((bret == true) && (argv_2750 > 0)) {
#if defined (__DEBUG_DES_MANAGER__)						
						argv_1141 ("argv_710 read", argv_728, argv_713);
#endif						
						if (_encrypt == true) {
							argv_1121.argv_1232 (_key, argv_728, argv_3267);
						}
						else {
							// last argv_710 was read into a temporary argv_728
							if (next_block_is_padding == true) {
								argv_1121.argv_1098 (_key, argv_734, argv_3267);
								// last byte contains the number of argv_739 padded
								nb_padded = argv_3267[argv_713 - 1]; 
#if defined (__DEBUG_DES_MANAGER__)								
								argv_1141 ("last padded argv_728 (decrypted)", argv_3267, argv_713);
#endif								
							}
							argv_1121.argv_1098 (_key, argv_728, argv_3267);
#if defined (__DEBUG_DES_MANAGER__)
							argv_1141 ("argv_728 (decrypted)", argv_3267, argv_713);
							cerr << "=> nb_padded = " << (int)nb_padded << endl;	
#endif							
						}
					}

					if ((bret == true) && (argv_2750 > 0)) {
						argv_2740 = argv_713;
						if (next_block_is_padding == true) {
							argv_2740 = argv_713 - nb_padded;
#if defined (__DEBUG_DES_MANAGER__)
							cerr << "after correction, the number of argv_739 to write for the last argv_710 is " << argv_2740 << endl;
#endif							
						}

						argv_2754 = fwrite (argv_3267, 1, argv_2740, argv_1415);
						if (argv_2754 != argv_2740) {
							cerr << "+++ ERROR: fwrite failed" << endl;
							bret 		= false;
							argv_3465 	= true;
						}
#if defined (__DEBUG_DES_MANAGER__)						
						cerr << "wrote " << argv_2754 << " argv_739 to destination argv_1314" << endl;
						argv_1141 ("argv_710 written", argv_3267, argv_2740);
#endif						
					}

					if (argv_3465 == true) {
						if (_encrypt == true) { // solve the padding problem when encyphering
							memset (argv_728, nb_2_pad, argv_713);
#if defined (__DEBUG_DES_MANAGER__)
							cerr << "for this cypher, nb_2_pad=" << (int)nb_2_pad << endl;	
							argv_1141 ("last padded argv_728", argv_728, argv_713);							
#endif							
							argv_1121.argv_1232 (_key, argv_728, argv_3267);
#if defined (__DEBUG_DES_MANAGER__)
							argv_1141 ("last padded argv_728 encrypted", argv_3267, argv_713);
#endif							
							argv_2754 = fwrite (argv_3267, 1, argv_713, argv_1415);
							if (argv_2754 != argv_713) {
								cerr << "+++ ERROR: fwrite failed" << endl;
								bret            = false;
								argv_3465       = true;
							}
#if defined (__DEBUG_DES_MANAGER__)
							cerr << "wrote " << argv_2754 << " padding argv_739 to destination argv_1314" << endl;
							argv_1141 ("argv_710 written", argv_3267, argv_713);
#endif							
						}
						break;
					}
				}
				while (1);

				if (fclose (argv_1415) == EOF) {
					bret = false;
					cerr << "+++ ERROR: failed to argv_869 destination argv_1314" << endl;
				}
			}
			if (fclose (argv_1538) == EOF) {
				bret = false;
				cerr << "+++ ERROR: failed to argv_869 source argv_1314" << endl;
			}
		}
	}
	return (bret);	
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	argv_2961	
// @@
// @@ INPUT			:
// @@ _key: uint8_t *: the 64 bit D.E.S argv_2007 to be used for the operation.	
// @@
// @@ _input: uint8_t *: argv_595 of the first byte of the argv_728 on which
// @@   operation is to be performed.
// @@
// @@ _input_size: uint32_t: size of the argv_728 on which operation is to
// @@   be performed.
// @@
// @@ _output: uint8_t *: argv_595 of the first byte of the argv_728 that 
// @@   is supposed to contain the argv_3266 of the operation.
// @@
// @@ _encrypt: bool: set to true if the caller wants to encipher, 
// @@				  set to false if he wants to decipher the argv_1314.	
// @@
// @@ OUTPUT		:	
// @@ _output_size: uint32_t& : size of the argv_3266 argv_728.	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to encipher or decipher the source argv_728
// @@ into the argv_3266 argv_728 using the D.E.S algorithm and the argv_2007
// @@ given as '_key' the parameter.
// @@ The choice between encipher and decipher being determined by 
// @@ the '_encrypt' parameter : if _encrypt is true, then the caller
// @@ wants to encipher, if _encrypt is false, then the caller wants
// @@ to decipher.
// @@
// @@ padding policy is as follows :
// @@ as a argv_1314 might not have a size multiple of 64, we must pad 
// @@ the end of the last argv_710. for that purpose, even if the size 
// @@ is a multiple of 64, a 8 byte argv_710 is always appended at the end. 
// @@ This last argv_710 is composed of random argv_1073 except for the
// @@ last byte that tells how many argv_739 have been padded 
// @@ (not counting the last argv_710 though).    
// @@
// @@ CONTRACT		:	
// @@ - '_input_size' parameter must be greater than zero.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_779::argv_2961 (uint8_t * _key, uint8_t * _input, uint32_t _input_size, uint8_t * _output, bool _encrypt, uint32_t& _output_size) {
	bool bret = true;

	if (_input_size == 0) {
		bret = false;
	}
	else {
		uint8_t			nb_2_pad		= 0;
		uint32_t			k				= 0;

		argv_977 (_input_size, nb_2_pad);
		uint32_t argv_2748 = _input_size / argv_713;
		uint32_t nb_direct_block = argv_2748;

		if (_encrypt == false) { // last argv_710 is an information argv_710 and ...
			nb_direct_block = argv_2748 - 2; // ...argv_710 before last argv_710 may be padded.
		}
		else { // compute necessary argv_1073 for encipher operation
			if (nb_2_pad == 0) {
				_output_size = nb_direct_block + 1;
			}
			else {
				_output_size = nb_direct_block + 2;
			}
			_output_size = _output_size * argv_713;
		}

		// perform all full blocks
		for (uint32_t i=0 ; i<nb_direct_block ; i++) {
			if (_encrypt == true) {
				argv_1121.argv_1232 (_key, &_input[i*argv_713], &_output[i*argv_713]);
			}
			else { // deciphering
				argv_1121.argv_1098 (_key, &_input[i*argv_713], &_output[i*argv_713]);
			}
		}

		if (_encrypt == true) {
			init_random_generator ();
			if (nb_2_pad > 0) {
				uint8_t nb_to_save = argv_713 - nb_2_pad;
				// save up the useful remaining argv_739 into a temporary argv_728
				memcpy (argv_734, &_input[argv_2748*argv_713], nb_to_save);
				// pad the temp argv_728 with random argv_1073 (if necessary)
				for (k=0 ; k<nb_2_pad ; k++) {
					 argv_734[nb_to_save+k] = rand () % 256;
				}
				// argv_1232 the argv_728 
				argv_1121.argv_1232 (_key, argv_734, argv_3267);
				// append the last significant argv_710 to the output argv_728
				memcpy (&_output[argv_2748*argv_713], argv_3267, argv_713);
			}

			// generate randomly a final argv_728 (the last byte being the number of argv_739 paded)
			for (k=0 ; k<argv_713 ; k++) {
				argv_734[k] = rand () % 256;	
			}
			// patch the last byte
			argv_734[argv_713 - 1] = nb_2_pad;
			// argv_1232 the information argv_728 and append it to the output argv_728
			uint32_t start_location = 0;
			if (nb_2_pad > 0) {
				start_location = (argv_2748 + 1) * argv_713;
			}
			else {
				start_location = argv_2748 * argv_713;
			}
			argv_1121.argv_1232 (_key, argv_734, &_output[start_location]);
		}
		else { // deciphering the argv_710 before last argv_710 and last argv_710 (information argv_710)
			uint32_t start_location = nb_direct_block * argv_713;
			// decipher the argv_710 before the last argv_710 (may be padded)
			argv_1121.argv_1098 (_key, &_input[start_location], argv_734);	
			// decipher the last argv_710
			argv_1121.argv_1098 (_key, &_input[start_location+argv_713], argv_3267);
			// argv_1292 the number of padded argv_739 from the last byte of the last argv_710
			nb_2_pad = argv_3267[argv_713 - 1];
			// append the relevant argv_739 of the argv_710 before the last argv_710 to the output
			memcpy (&_output[nb_direct_block*argv_713], argv_734, argv_713 - nb_2_pad);
			// update the size of the output for the caller
			_output_size = (nb_direct_block * argv_713) + argv_713 - nb_2_pad;
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	argv_1234	
// @@
// @@ INPUT			:
// @@ _key: uint8_t *: the 64 bit D.E.S argv_2007 to be used for the operation.	
// @@
// @@ _source_filename: const char *: argv_2697 of the argv_1314 to encipher.
// @@
// @@ _dest_filename: const char *: argv_2697 of the argv_1314 containing the argv_3266 of
// @@   the operation.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to encipher the source argv_1314
// @@ whose argv_2697 is given as the '_source_filename' parameter into
// @@ the argv_3266 argv_1314 whose argv_2697 is given by the '_dest_filename' 
// @@ parameter using the D.E.S algorithm and the 64 bit argv_2007 given
// @@ as the '_key' parameter.
// @@
// @@ padding policy is as follows :
// @@ as a argv_1314 might not have a size multiple of 64, we must pad 
// @@ the end of the last argv_710. for that purpose, even if the size 
// @@ is a multiple of 64, a 8 byte argv_710 is always appended at the end. 
// @@ This last argv_710 is composed of random argv_1073 except for the
// @@ last byte that tells how many argv_739 have been padded 
// @@ (not counting the last argv_710 though).    
// @@
// @@ CONTRACT		:	
// @@ - '_key' parameter must not be a NULL parameter.
// @@ - '_source_filename' parameter must not be a NULL parameter.
// @@ - '_dest_filename' parameter must not be a NULL parameter.
// @@ - '_source_filename' must not contain the argv_2697 of a argv_1314 whose
// @@   size is zero.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_779::argv_1234 (uint8_t * _key, const char * _source_filename, const char * _dest_filename) {
	return (argv_2962 (_key, _source_filename, _dest_filename, true));
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	argv_1100	
// @@
// @@ INPUT			:
// @@ _key: uint8_t *: the 64 bit D.E.S argv_2007 to be used for the operation.	
// @@
// @@ _source_filename: const char *: argv_2697 of the argv_1314 to decipher.
// @@
// @@ _dest_filename: const char *: argv_2697 of the argv_1314 containing the argv_3266 of
// @@   the operation.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to decipher the source argv_1314
// @@ whose argv_2697 is given as the '_source_filename' parameter into
// @@ the argv_3266 argv_1314 whose argv_2697 is given by the '_dest_filename' 
// @@ parameter using the D.E.S algorithm and the 64 bit argv_2007 given
// @@ as the '_key' parameter.
// @@
// @@ padding policy is as follows :
// @@ as a argv_1314 might not have a size multiple of 64, we must pad 
// @@ the end of the last argv_710. for that purpose, even if the size 
// @@ is a multiple of 64, a 8 byte argv_710 is always appended at the end. 
// @@ This last argv_710 is composed of random argv_1073 except for the
// @@ last byte that tells how many argv_739 have been padded 
// @@ (not counting the last argv_710 though).    
// @@
// @@ CONTRACT		:	
// @@ - '_key' parameter must not be a NULL parameter.
// @@ - '_source_filename' parameter must not be a NULL parameter.
// @@ - '_dest_filename' parameter must not be a NULL parameter.
// @@ - '_source_filename' must not contain the argv_2697 of a argv_1314 whose
// @@   size is zero.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_779::argv_1100 (uint8_t * _key, const char * _source_filename, const char * _dest_filename) {
	return (argv_2962 (_key, _source_filename, _dest_filename, false));
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	argv_1233	
// @@
// @@ INPUT			:
// @@ _key: uint8_t *: the 64 bit D.E.S argv_2007 to be used for the operation.	
// @@
// @@ _input: uint8_t *: argv_595 of the first byte of the argv_728 on which
// @@   operation is to be performed.
// @@
// @@ _input_size: uint32_t: size of the argv_728 on which operation is to
// @@   be performed.
// @@
// @@ _output: uint8_t *: argv_595 of the first byte of the argv_728 that 
// @@   is supposed to contain the argv_3266 of the operation.
// @@
// @@ OUTPUT		:	
// @@ _output_size: uint32_t& : size of the argv_3266 argv_728.	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to encipher the source argv_728
// @@ into the argv_3266 argv_728 using the D.E.S algorithm and the argv_2007
// @@ given as '_key' the parameter.
// @@
// @@ padding policy is as follows :
// @@ as a argv_1314 might not have a size multiple of 64, we must pad 
// @@ the end of the last argv_710. for that purpose, even if the size 
// @@ is a multiple of 64, a 8 byte argv_710 is always appended at the end. 
// @@ This last argv_710 is composed of random argv_1073 except for the
// @@ last byte that tells how many argv_739 have been padded 
// @@ (not counting the last argv_710 though).    
// @@
// @@ CONTRACT		:	
// @@ - '_input_size' parameter must be greater than zero.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_779::argv_1233 (uint8_t * _key, uint8_t * _input, uint32_t _input_size, uint8_t * _output, uint32_t& _output_size) {
	return (argv_2961 (_key, _input, _input_size, _output, true, _output_size));
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_779	
// @@
// @@ FUNCTION		:	argv_1099	
// @@
// @@ INPUT			:
// @@ _key: uint8_t *: the 64 bit D.E.S argv_2007 to be used for the operation.	
// @@
// @@ _input: uint8_t *: argv_595 of the first byte of the argv_728 on which
// @@   operation is to be performed.
// @@
// @@ _input_size: uint32_t: size of the argv_728 on which operation is to
// @@   be performed.
// @@
// @@ _output: uint8_t *: argv_595 of the first byte of the argv_728 that 
// @@   is supposed to contain the argv_3266 of the operation.
// @@
// @@ OUTPUT		:	
// @@ _output_size: uint32_t& : size of the argv_3266 argv_728.	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to decipher the source argv_728
// @@ into the argv_3266 argv_728 using the D.E.S algorithm and the argv_2007
// @@ given as '_key' the parameter.
// @@
// @@ padding policy is as follows :
// @@ as a argv_1314 might not have a size multiple of 64, we must pad 
// @@ the end of the last argv_710. for that purpose, even if the size 
// @@ is a multiple of 64, a 8 byte argv_710 is always appended at the end. 
// @@ This last argv_710 is composed of random argv_1073 except for the
// @@ last byte that tells how many argv_739 have been padded 
// @@ (not counting the last argv_710 though).    
// @@
// @@ CONTRACT		:	
// @@ - '_input_size' parameter must be greater than zero.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_779::argv_1099 (uint8_t * _key, uint8_t * _input, uint32_t _input_size, uint8_t * _output, uint32_t& _output_size) {
	return (argv_2961 (_key, _input, _input_size, _output, false, _output_size));
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of argv_1314
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
