import * as app from '../app';
import { Memo } from '../app';

   let isGetCalled: boolean = false;
    async function dummyGetLatestMemo(
      memoId: String
    ): Promise<any> {
      const mockData = `It is mock data ${memoId}`;
      isGetCalled = true;
      return Promise.resolve(mockData);
    }

describe('Test Memo with 2nd layer mock function by static function in class', () => {
  it('should run ok', async() => {

      let r = await app.handleMemo();
      console.log(r);
      expect(isGetCalled).toBe(false);

      jest.spyOn(Memo, 'getLatestMemo')
            .mockImplementation(dummyGetLatestMemo);
      r = await app.handleMemo();
      console.log(r);
      expect(isGetCalled).toBe(true);
  });
});