/* * 
 *  $Id$
 *  
 *  This file is part of Fenice
 *
 *  Fenice -- Open Media Server
 *
 *  Copyright (C) 2004 by
 * 
 *  - (LS)� Team			<team@streaming.polito.it>	
 *	- Giampaolo Mancini	<giampaolo.mancini@polito.it>
 *	- Francesco Varano	<francesco.varano@polito.it>
 *	- Federico Ridolfo	<federico.ridolfo@polito.it>
 *	- Marco Penno		<marco.penno@polito.it>
 * 
 *  Fenice is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  Fenice is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Fenice; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *  
 * */

#include <stdlib.h>
#include <stun/stun.h>

stun_atr *create_change_request(STUNbool port, STUNbool addr)
{
	stun_atr *atr = calloc(1,sizeof(stun_atr));
	if(atr == NULL)
		return NULL;
	atr->atr = (struct STUN_ATR_CHANGE_REQUEST *) \
   		   calloc(1,sizeof(struct STUN_ATR_ADDRESS));
	if(atr->atr == NULL) {
		free(atr);
		return NULL;
	}

	if(port)
		SET_CHANGE_PORT_FLAG(((struct  STUN_ATR_CHANGE_REQUEST *)
					(atr->atr))->flagsAB);
	if(addr)
		SET_CHANGE_ADDR_FLAG(((struct  STUN_ATR_CHANGE_REQUEST *)
					(atr->atr))->flagsAB);
	
	add_stun_atr_hdr(atr, CHANGE_REQUEST, sizeof(struct STUN_ATR_CHANGE_REQUEST));
	
	return atr;
}