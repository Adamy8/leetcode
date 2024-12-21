from typing import List

class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x: x[1], reverse=False) # sort based on endtime

        # maxsum is stored based on event end_time
        maxsum_dict = {}
        for i in range(len(events)):
            maxsum_dict[events[i][1]] = 0

        for i in range(len(events)):
            starts = events[i][0]
            ends = events[i][1]
            value = events[i][2]

            lastMax = 0
            lastMaxBeforeStart = 0
            if i != 0:
                lastMax = maxsum_dict[ events[i-1][1] ]
                for j in range(i, -1, -1):
                    if events[j][1] < starts:
                        lastMaxBeforeStart = maxsum_dict[events[j][1]]
                        break
            # print(i,", events[i-1][1]:",events[i-1][1],", starts:",starts,", dic:",maxsum_dict[events[i-1][1]])
            # print("lastmaxbefore:",lastMaxBeforeStart)
            maxsum_dict[events[i][1]] = max( lastMaxBeforeStart + value, lastMax )
            # print(maxsum_dict,"\n")

        return maxsum_dict[events[-1][1]]
    

# test cases
sol = Solution()
# events = [[1,3,2],[4,5,2],[2,4,3]]

# events = [[1,3,2],[4,5,2],[1,5,5]]

# events = [[1,5,3],[1,5,1],[6,6,5]]

events = [[10,83,53],[63,87,45],[97,100,32],[51,61,16]]

print(sol.maxTwoEvents(events))