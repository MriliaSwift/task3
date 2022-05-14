/*
 * File      : main.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2018, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-08-16     armink       first implementation
 */

#include <rtthread.h>
#include <task.h>

static void thread_entry(void *parameter)
{
rt_uint32_t value;
rt_uint32_t count = 0;
value = (rt_uint32_t)parameter;
while(1)
	
{
	if(0==(count%5))
	{
	rt_kprintf("thread%d is running,thread%d cout:%d\n",value,value,count);
if(count>200)
	return;

	}
	count++;
}
}

int task(void)
{ 

	rt_thread_t tid = RT_NULL;
	tid=rt_thread_create("thread1",thread_entry,(void*)1,THREAD_STACK_SIZE,
	THREAD_PRIORITY,THREAD1_TIMESLICE);
	if(tid != RT_NULL)
	rt_thread_startup(tid);
	// creat thread1
tid=rt_thread_create("thread2",thread_entry,(void*)2,THREAD_STACK_SIZE,
THREAD_PRIORITY,THREAD2_TIMESLICE);
	if(tid != RT_NULL)
	rt_thread_startup(tid);
	
	return 0;
	

}
int main(void)
{
    return 0;
}


MSH_CMD_EXPORT(task,task);
