class Solution:
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        mapping_group = [[] for _ in range(m)]
        for i, gid in enumerate(group):
            if gid == -1:
                group[i] = m
                m += 1
                mapping_group.append([i])
                continue
            mapping_group[gid].append(i)

        graph_item = [[] for _ in range(n)]
        ind_item = [0] * n
        ind_group = [0] * m
        
        for i, vec in enumerate(beforeItems):
            ind_item[i] = len(vec)
            for j in vec:
                graph_item[j].append(i)
                if group[j] != group[i]:
                    ind_group[group[i]] += 1
        
        visited_gid = [False] * m
        visited_item = [False] * n
        q_gid = deque()
        ans = []

        for gid, ind in enumerate(ind_group):
            if ind == 0: 
                q_gid.append(gid)
                visited_gid[gid] = True
        q_item = deque()
        while q_gid:
            gid = q_gid.popleft()
            for iid in mapping_group[gid]:
                if ind_item[iid] == 0:
                    q_item.append(iid)
                    visited_item[iid] = True
            
            while q_item:
                iid = q_item.popleft()
                ans.append(iid)
                for neit in graph_item[iid]:
                    ind_item[neit] -= 1
                    if group[neit] != gid: ind_group[group[neit]] -= 1
                    if visited_item[neit] == False and group[neit] == gid and ind_item[neit] == 0:
                        q_item.append(neit)
                        visited_item[neit] = True
                    
                    if visited_gid[group[neit]] == False and ind_group[group[neit]] == 0:
                        q_gid.append(group[neit])
                        visited_gid[group[neit]] = True

        return ans if len(ans) == n else []