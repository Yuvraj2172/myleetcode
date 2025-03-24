class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        merge_meetings = []
        
        meetings.sort()
        for meeting in meetings:
            if not merge_meetings or merge_meetings[-1][1] < meeting[0]:
                merge_meetings.append(meeting)
            else:
                merge_meetings[-1][1] = max(merge_meetings[-1][1],meeting[1])
                
        ans = 0
        print(merge_meetings)
        for start,end in merge_meetings:
            ans += (end - start +1)
        return days - ans
