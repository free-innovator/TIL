#include <stdio.h>
#include <string.h>

#define MAX_BUF 100
#define QUANTUM	5

#pragma warning(disable:4996)

/* struct declaration */ 
typedef struct _process_info
{ 
	int id;
	int arrive_time;
	int burst_time;
	char type[10];
}ProcessInfo;

/* global function */
void GetProcessInfo(ProcessInfo p_info[], const int count);
void ShowProcessInfo(ProcessInfo p_info[], const int count);

void PushProcess(ProcessInfo info[], ProcessInfo* ref);
void ExecScheduler(ProcessInfo p_info[], ProcessInfo result_info[]);

void SwapProcess(ProcessInfo* first, ProcessInfo* second);
void SwapInt(int *a, int *b);
void EraseProcess(ProcessInfo p_info[], const int index);
void ArrangeIO(ProcessInfo p_info[], const int turnaround_time);

/* global variable */
int wait_time = 0, turnaround_time = 0, idle_time = 0;
int result_count = 0;
int process_count = 11;

int main(void)
{
	ProcessInfo p_info[11];
	ProcessInfo result_info[MAX_BUF];

	GetProcessInfo(p_info, process_count);
	puts("*ShowProcessInfo*");
	puts("-----------------");
	ShowProcessInfo(p_info, process_count);
	puts("-----------------\n");

	ExecScheduler(p_info, result_info);

	puts("**************Result Info****************");
	ShowProcessInfo(result_info, result_count);
	printf("turnaround time\t\t: %d\n", turnaround_time);
	printf("average wait time\t: %g\n", (double)wait_time/3.0);
	printf("cpu utilization\t\t: %.4g%%\n", ((double)turnaround_time-idle_time)/turnaround_time*100);
	puts("*****************************************");

	return 0;
}

void GetProcessInfo(ProcessInfo p_info[], const int count)
{
	int i = 0;
	FILE *fp = fopen("value.txt", "rt");
	
	for(i=0; i<count; i++)
		fscanf(fp, "p%d, %d, %d, %s\n", &p_info[i].id, &p_info[i].arrive_time, &p_info[i].burst_time, p_info[i].type);

	fclose(fp);
}
void ShowProcessInfo(ProcessInfo p_info[], const int count)
{
	int i = 0;
	for(i=0; i<count; i++)
		printf("p%d, %d, %d, %s\n", p_info[i].id, p_info[i].arrive_time, p_info[i].burst_time, p_info[i].type);
}

void PushProcess(ProcessInfo info[], ProcessInfo* ref)
{
	info[result_count].arrive_time = ref->arrive_time;
	info[result_count].burst_time = ref->burst_time;
	info[result_count].id = ref->id;
	strcpy(info[result_count].type, ref->type);
	result_count++;
}

void ExecScheduler(ProcessInfo p_info[], ProcessInfo result_info[])
{
	int i = 0;
	int cycle = 0, acc = 0 ;
	int min_arrive_index = 0;
	int min_arrive_value = 0;
	ProcessInfo push_info;
	ProcessInfo *min_info = NULL;
	
	while(process_count > 0)
	{
		// search min_arrive
		min_arrive_value = p_info[0].arrive_time;
		min_arrive_index = 0;
		for(i = 0; i < process_count; i++){
			if(p_info[i].arrive_time < min_arrive_value || 
				(p_info[i].arrive_time == min_arrive_value && strcmp(p_info[i].type, "CPU")==0))
			{
				min_arrive_value = p_info[i].arrive_time;
				min_arrive_index = i;
			}
		}
		min_info = &p_info[min_arrive_index];

		// calculate process
		if(strcmp(min_info->type, "CPU")==0)
		{
			// result push
			push_info.id = min_info->id;
			push_info.arrive_time = turnaround_time;
			push_info.burst_time = (min_info->burst_time <= QUANTUM)? min_info->burst_time : QUANTUM;
			strcpy(push_info.type, "CPU");
			PushProcess(result_info, &push_info);

			// OTHER process info renew
			acc = turnaround_time + min_info->burst_time;
			for(i=0; i<process_count; i++){
				if(min_arrive_index != i && min_info->id == p_info[i].id)
				{
					p_info[i].arrive_time = acc;
					acc += p_info[i].burst_time;
				}
			}

			wait_time += turnaround_time - min_info->arrive_time;
			// process info renew
			if(min_info->burst_time <= QUANTUM){
				turnaround_time += min_info->burst_time;
				EraseProcess(p_info, min_arrive_index);
			}
			else
			{
				turnaround_time += QUANTUM;
				min_info->burst_time -= QUANTUM;
				min_info->arrive_time = turnaround_time;
			}
		}
		else // io
		{
			if(turnaround_time >= min_info->arrive_time + min_info->burst_time)
			{
				EraseProcess(p_info, min_arrive_index);
				continue;
			}
			else
			{	
				for(i = 0; i < process_count; i++){
					if(strcmp(p_info[i].type, "CPU")==0)
					{
						min_arrive_value = p_info[i].arrive_time;
						min_arrive_index = i;
						break;
					}
				}
				for(i = 0; i < process_count; i++){
					if(strcmp(p_info[i].type, "CPU")==0)
						if(p_info[i].arrive_time < min_arrive_value)
						{
							min_arrive_value = p_info[i].arrive_time;
							min_arrive_index = i;
						}
				}
				min_info = &p_info[min_arrive_index];

				if(strcmp(min_info->type, "IO")==0)
					;// ... CPU가 없고 IO만 남았을 경우. 생략한다.!
				else{
					// push idle info
					if(min_info->arrive_time > turnaround_time)
					{
						idle_time += min_info->arrive_time - turnaround_time;					

						push_info.id = min_info->id;
						push_info.arrive_time = turnaround_time;
						push_info.burst_time = idle_time;
						strcpy(push_info.type, "IO");
						PushProcess(result_info, &push_info);

						turnaround_time = min_info->arrive_time;
						ArrangeIO(p_info, turnaround_time);
					}
					else
					{
						ArrangeIO(p_info, turnaround_time);
						continue;
					}
				}
			}
		}

		printf("--- %d Cycle -- %d turnaround time ---\n", ++cycle, turnaround_time);
		ShowProcessInfo(p_info, process_count);
		getchar();
	}	
}

void SwapProcess(ProcessInfo* first, ProcessInfo* second)
{
	char temp[10];
	SwapInt(&first->id			, &second->id);
	SwapInt(&first->arrive_time	, &second->arrive_time);
	SwapInt(&first->burst_time	, &second->burst_time);	
	strcpy(temp			, first->type);
	strcpy(first->type	, second->type);
	strcpy(second->type	, temp);
}
void SwapInt(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void EraseProcess(ProcessInfo p_info[], const int index)
{
	int i = 0;
	for(i=index+1; i<process_count; i++)
	{
		SwapProcess(&p_info[i-1], &p_info[i]);
	}
	process_count--;
}
void ArrangeIO(ProcessInfo p_info[], const int turnaround_time)
{			
	int i = 0;
	for(i = 0; i < process_count; i++){
		if(strcmp(p_info[i].type, "IO")==0)
		{
			if(turnaround_time >= p_info[i].arrive_time + p_info[i].burst_time)
			{
				EraseProcess(p_info, i);
				i--; // 지워져서 한칸 뒤로.
			}
			else
			{
				p_info[i].burst_time -= turnaround_time - p_info[i].arrive_time;
				p_info[i].arrive_time = turnaround_time;							
			}
		}
	}
}